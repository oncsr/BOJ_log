#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> V(300001), C(300001);
vector<int> A(300001), S(300001), E(300001), seg(1048577);
int N, M, R, c = 0;
int par[300001]{}, sz[300001]{}, cn[300001]{}, ci[300001]{}, dep[300001]{};
set<int> T;
int cnt[600001]{};
vector<int> ans(300001);

void sol(int n, int p, int g){
    cnt[A[n]]++;
    T.erase(A[n]);
    ans[n] = *T.begin();
    for(int i:V[n]) if(i != p)  sol(i,n,g);
    cnt[A[n]]--;
    if(!cnt[A[n]])  T.insert(A[n]);
}

void dfs(int n, int p){
    S[n] = ++c;
    par[n] = p, sz[n] = 1;
    for(int i:V[n]) if(i != p)  dfs(i,n), sz[n] += sz[i];
    E[n] = c;
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    int h = -1;
    for(int i:V[n]) if(i != p && (h == -1 || sz[i] > sz[h]))    h = i;
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

void upt(int s, int e, int i, int v, int n){
    if(s==e){
        seg[n] ^= v;
        return;
    }
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,v,n*2);
    else    upt(m+1,e,i,v,n*2+1);
    seg[n] = seg[n*2] ^ seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
    if(l>r||l>e||r<s)   return 0;
    if(l<=s && e<=r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2)^find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>R;
    for(int i=1;i<=N;i++)   cin>>A[i];
    for(int i=1,a,b;i<N;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(R,0);
    hld(R,0,R,0);

    for(cin>>M;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        int g = lca(a,b);
        upt(1,N,S[a],c,1);
        upt(1,N,S[b],c,1);
        upt(1,N,S[g],c,1);
        if(g != R)  upt(1,N,S[par[g]],c,1);
    }
    for(int i=1;i<=N;i++)   A[i] ^= find(1,N,S[i],E[i],1);
    for(int i=0;i<=N*2;i++)   T.insert(i);
    sol(R,0,0);
    for(int i=1;i<=N;i++)   cout<<ans[i]<<' ';

}