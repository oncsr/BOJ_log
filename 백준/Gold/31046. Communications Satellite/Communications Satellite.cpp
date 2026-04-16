#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int N;
   tuple<ld, ld, ld> arr[2000]{};
   cin>>N;
   for(int i=0;i<N;i++){
      int a,b,c;
      cin>>a>>b>>c;
      arr[i] = {a,b,c};
   }
   vector<tuple<ld, int, int>> edge;
   for(int i=0;i<N;i++){
      auto [x,y,c] = arr[i];
      for(int j=i+1;j<N;j++){
         auto [p,q,r] = arr[j];
         ld cost = sqrtl((x-p)*(x-p) + (y-q)*(y-q)) - c - r;
         edge.emplace_back(cost,i,j);
      }
   }
   sort(edge.begin(), edge.end());

   int root[2000]{};
   iota(root, root+N, 0);
   function<int(int)> find = [&](int x) -> int {
      if(x == root[x])  return x;
      return root[x] = find(root[x]);
   };

   ld ans = 0;
   for(auto [c,a,b]:edge){
      int x = find(a), y = find(b);
      if(x == y)  continue;
      ans += c;
      root[x] = y;
   }
   cout.precision(10);
   cout<<fixed<<ans;


}