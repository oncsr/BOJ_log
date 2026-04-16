#include <bits/stdc++.h>
using namespace std;

int par[100001]{}, sz[100001]{}, cn[100001]{}, ci[100001]{}, dep[100001]{};
vector<vector<pair<int,int>>> V(100001);
vector<vector<int>> C(100001);
int seg[262145]{}, ord[100001]{}, rev[100001]{}, cnt = 0, arr[100001]{}, N;

void dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(auto [i,c]:V[n]){
        if(i == p)  continue;
        dfs(i,n);
        arr[i] = c;
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    ord[n] = ++cnt;
    rev[cnt] = n;
    int h = -1;
    for(auto [i,c]:V[n])    if(i != p && (h == -1 || sz[i] > sz[h]))   h = i;
    if(h != -1) hld(h,n,s,d);
    for(auto [i,c]:V[n])    if(i != p && i != h)  hld(i,n,i,d+1);
}

int init(int s, int e, int n){
    if(s == e)  return seg[n] = arr[rev[s]];
    int m=(s+e)>>1;
    return seg[n] = init(s,m,n*2) + init(m+1,e,n*2+1);
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l<=s && e<=r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int sol(int a, int b){
    int res = 0;
    while(cn[a] != cn[b]){
        if(dep[a] > dep[b]){
            res += find(1,N,ord[cn[a]],ord[a],1);
            a = par[cn[a]];
        }
        else{
            res += find(1,N,ord[cn[b]],ord[b],1);
            b = par[cn[b]];
        }
    }
    int g = ci[a] < ci[b] ? a : b, c = g == a ? b : a;
    return res + find(1,N,ord[g]+1,ord[c],1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    
    int Q;
    cin>>N>>Q;
    for(int i=1,a,b,c;i<N;i++){
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    dfs(1,0);
    hld(1,0,1,0);
    init(1,N,1);
    
    for(int a,b;Q--;){
        cin>>a>>b;
        cout<<sol(a,b)<<'\n';
    }
}