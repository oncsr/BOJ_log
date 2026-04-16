#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> V(100001), C(100001);
int par[100001]{}, cn[100001]{}, ci[100001]{}, sz[100001]{}, dep[100001]{};

int seg[262145]{}, lazy[262145]{}, ord[100001]{}, cnt = 0;

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
   int h = -1;
   ord[n] = ++cnt;
   for(int i:V[n])   if(i != p && (h == -1 || sz[i] > sz[h]))  h = i;
   if(h != -1) hld(h,n,s,d);
   for(int i:V[n])   if(i != p && i != h) hld(i,n,i,d+1);
}

int lca(int a, int b){
   while(cn[a] != cn[b]){
      if(dep[a] > dep[b])  a = par[cn[a]];
      else  b = par[cn[b]];
   }
   return ci[a] < ci[b] ? a : b;
}

void prop(int s, int e, int n){
   if(lazy[n]){
      int v = lazy[n];
      seg[n] = v;
      if(s != e)  lazy[n*2] = lazy[n*2+1] = v;
      lazy[n] = 0;
   }
}

void upt(int s, int e, int l, int r, int v, int n){
   prop(s,e,n);
   if(l>r || l>e || r<s)   return;
   if(l <= s && e <= r){
      seg[n] = v;
      if(s != e)  lazy[n*2] = lazy[n*2+1] = v;
      return;
   }
   int m=(s+e)>>1;
   upt(s,m,l,r,v,n*2);  upt(m+1,e,l,r,v,n*2+1);
}

int find(int s, int e, int i, int n){
   prop(s,e,n);
   if(s == e)  return seg[n];
   int m=(s+e)>>1;
   if(i <= m)  return find(s,m,i,n*2);
   return find(m+1,e,i,n*2+1);
}

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N;
   cin>>N;
   for(int i=1;i<N;i++){
      int a,b;
      cin>>a>>b;
      V[a].push_back(b);
      V[b].push_back(a);
   }
   dfs(1,0);
   hld(1,0,1,0);

   int Q, c = 0;
   for(cin>>Q;Q--;){
      int o,a,b;
      cin>>o>>a;
      if(o == 2){
         cout<<find(1,N,ord[a],1)<<'\n';
         continue;
      }
      cin>>b;
      c++;
      int g = lca(a,b);
      while(cn[g] != cn[a]){
         upt(1,N,ord[cn[a]],ord[a],c,1);
         a = par[cn[a]];
      }
      while(cn[g] != cn[b]){
         upt(1,N,ord[cn[b]],ord[b],c,1);
         b = par[cn[b]];
      }
      upt(1,N,ord[g],ord[a],c,1);
      upt(1,N,ord[g],ord[b],c,1);
   }

}