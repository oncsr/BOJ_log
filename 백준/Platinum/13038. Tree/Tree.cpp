#include <bits/stdc++.h>
using namespace std;

int seg[262145]{};
int arr[100001]{};
vector<vector<int>> V(100001);
vector<vector<int>> C(100001);
int par[100001]{}, sz[100001]{}, dep[100001]{}, cn[100001]{}, ci[100001]{};
int ord[100001]{}, cnt = 0;

void dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(int i:V[n]){
        if(i == p)  continue;
        dfs(i,n);
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    ord[n] = ++cnt;
    int h = -1;
    for(int i:V[n]) if(i != p && (h == -1 || sz[i] > sz[h])) h = i;
    if(h != -1) hld(h,n,s,d);
    for(int i:V[n]) if(i != p && i != h)    hld(i,n,i,d+1);
}

int lca(int a, int b){
    while(cn[a] != cn[b]){
        if(dep[a] > dep[b]) a = par[cn[a]];
        else    b = par[cn[b]];
    }
    return ci[a] < ci[b] ? a : b;
}

void init(int s, int e, int n){
    if(s == e){
        seg[n] = s == 1 ? 0 : 1;
        return;
    }
    int m=(s+e)>>1;
    init(s,m,n*2);
    init(m+1,e,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

void upt(int s, int e, int i, int n){
    if(s==e){
        seg[n]--;
        return;
    }
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,n*2);
    else    upt(m+1,e,i,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        int a;
        cin>>a;
        V[a].push_back(i);
    }
    dfs(1,0);
    hld(1,0,1,0);
    init(1,N,1);
    int Q;
    for(cin>>Q;Q--;){
        int o, a, b;
        cin>>o>>a;
        if(o == 2)  upt(1,N,ord[a],1);
        else{
            cin>>b;
            int g = lca(a,b);
            int res = 0;
            while(cn[a] != cn[g]){
                res += find(1,N,ord[cn[a]], ord[a],1);
                a = par[cn[a]];
            }
            if(a != g)  res += find(1,N,ord[g]+1,ord[a],1);
            while(cn[b] != cn[g]){
                res += find(1,N,ord[cn[b]], ord[b],1);
                b = par[cn[b]];
            }
            if(b != g)  res += find(1,N,ord[g]+1,ord[b],1);
            cout<<res<<'\n';
        }
    }
    
}