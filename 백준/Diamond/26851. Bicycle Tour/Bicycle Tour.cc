#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<pair<int, int>>> V(100001);
vector<ll> H(100001);

vector<vector<int>> C(100001);
int dep[100001]{}, sz[100001]{}, par[100001]{}, cn[100001]{}, ci[100001]{};
int ord[100001]{}, rev[100001]{}, cnt = 0;
vector<int> seg(262145, 2e9);
vector<int> lazy(262145, 2e9);
vector<int> ans(100001, -1);

void dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(auto [i,c]:V[n]){
        if(i == p)  continue;
        dfs(i,n);
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
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

void prop(int s, int e, int n){
    if(lazy[n] != 2e9){
        if(s != e)  lazy[n*2] = lazy[n*2+1] = lazy[n];
        else    seg[n] = ans[rev[s]] = lazy[n];
        lazy[n] = 2e9;
    }
}

void upt(int s, int e, int l, int r, int v, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s)   return;
    if(l <= s && e <= r){
        if(s != e)  lazy[n*2] = lazy[n*2+1] = v;
        else    seg[n] = ans[rev[s]] = v;
        return;
    }
    int m=(s+e)>>1;
    upt(s,m,l,r,v,n*2); upt(m+1,e,l,r,v,n*2+1);
}

void cle(int s, int e, int n){
    prop(s,e,n);
    if(s == e)  return;
    int m=(s+e)>>1;
    cle(s,m,n*2); cle(m+1,e,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++)   cin>>H[i];
    vector<tuple<int, int, int>> E(M);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        E[i] = {abs(H[a]-H[b]),a,b};
    }
    sort(E.begin(), E.end());

    vector<int> used(M);
    vector<int> root(100001);
    iota(root.begin(), root.end(), 0);
    function<int(int)> find_root = [&](int x) -> int {
        if(x == root[x])    return x;
        return root[x] = find_root(root[x]);
    };
    for(int i=0;i<M;i++){
        auto [c,a,b] = E[i];
        int x = find_root(a), y = find_root(b);
        if(x == y)  continue;
        used[i]++;
        root[x] = y;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    dfs(1,0);
    hld(1,0,1,0);

    for(int i=M-1;i>=0;i--){
        if(used[i]) continue;
        auto [c,a,b] = E[i];
        int g = lca(a,b);
        while(cn[g] != cn[a]){
            upt(1,N,ord[cn[a]],ord[a],c,1);
            a = par[cn[a]];
        }
        upt(1,N,ord[g],ord[a],c,1);
        while(cn[g] != cn[b]){
            upt(1,N,ord[cn[b]],ord[b],c,1);
            b = par[cn[b]];
        }
        upt(1,N,ord[g],ord[b],c,1);
    }

    cle(1,N,1);
    for(int i=1;i<=N;i++)   cout<<ans[i]<<' ';

}