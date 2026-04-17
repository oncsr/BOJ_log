#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[7001]{};
int N, M;
int find(int x){
    if(x==root[x])  return x;
    return root[x] = find(root[x]);
}

vector<vector<pair<int, int>>> V(7001);
vector<vector<int>> C(7001);
int par[7001]{}, sz[7001]{}, cn[7001]{}, ci[7001]{}, dep[7001]{};
int seg[16385]{}, arr[7001]{}, ord[7001]{}, rev[7001]{}, cnt = 0;

int dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(auto [i,c]:V[n]){
        if(i == p)  continue;
        arr[i] = c;
        sz[n] += dfs(i,n);
    }
    return sz[n];
}

void hld(int n, int p, int s, int d){
    dep[n]=d, cn[n]=s, ci[n]=C[s].size();
    C[s].push_back(n);
    ord[n] = ++cnt;
    rev[cnt] = n;
    int h = -1;
    for(auto [i,c]:V[n])    if(i != p && (h == -1 || sz[i] > sz[h]))    h = i;
    if(h != -1) hld(h,n,s,d);
    for(auto [i,c]:V[n])    if(i != p && i != h)    hld(i,n,i,d+1);
}

int lca(int a, int b){
    while(cn[a] != cn[b]){
        if(dep[a] > dep[b]) a = par[cn[a]];
        else    b = par[cn[b]];
    }
    return ci[a] < ci[b] ? a : b;
}

int init(int s, int e, int n){
    if(s==e)    return seg[n] = arr[rev[s]];
    int m=(s+e)>>1;
    return seg[n] = max(init(s,m,n*2), init(m+1,e,n*2+1));
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return max(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    vector<tuple<int, int, int, int>> E;
    iota(root, root+N+1, 0);

    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        E.emplace_back(c,a,b,i);
    }
    sort(E.begin(), E.end());
    
    for(auto &[c,a,b,i]:E){
        int x = find(a), y = find(b);
        if(x==y)    continue;
        root[x] = y;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    dfs(1,0);
    hld(1,0,1,0);
    init(1,N,1);
    vector<int> ans(M);
    for(auto [c,a,b,i]:E){
        int g = lca(a,b);
        int res = 0;
        while(cn[a] != cn[g]){
            res = max(res, find(1,N,ord[cn[a]], ord[a],1));
            a = par[cn[a]];
        }
        res = max(res, find(1,N,ord[g]+1, ord[a],1));
        while(cn[b] != cn[g]){
            res = max(res, find(1,N,ord[cn[b]], ord[b],1));
            b = par[cn[b]];
        }
        res = max(res, find(1,N,ord[g]+1, ord[b],1));
        ans[i] = res == c;
    }
    for(int i=0;i<M;i++)    cout<<(ans[i]?"TAK\n":"NIE\n");

}