#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[100001]{};

int find(int x){
   if(x==root[x]) return x;
   return root[x] = find(root[x]);
}

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int N, M, Q;
   cin>>N>>M>>Q;
   vector<int> cnt(N+1, 1);
   iota(root, root+N+1, 0);
   vector<pair<int, int>> edge(M);
   for(auto &[a,b]:edge)   cin>>a>>b;
   vector<int> query(Q);
   vector<int> chk(M);
   for(int &i:query){
      cin>>i;
      i--;
      chk[i]++;
   }

   for(int i=0;i<M;i++){
      if(chk[i])  continue;
      auto [a,b] = edge[i];
      int x = find(a), y = find(b);
      if(x == y)  continue;
      root[x] = y;
      cnt[y] += cnt[x];
   }

   ll ans = 0;
   for(int &q:query){
      auto [a,b] = edge[q];
      int x = find(a), y = find(b);
      if(x == y)  continue;
      root[x] = y;
      ans += ll(cnt[x]) * cnt[y];
      cnt[y] += cnt[x];
   }
   cout<<ans;

}