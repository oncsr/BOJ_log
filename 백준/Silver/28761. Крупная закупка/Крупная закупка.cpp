#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int N, M, K, mx = -1;
   cin>>N>>M>>K;
   vector<pair<int, int>> V;
   for(int i=1;i<=N;i++){
      int a;
      cin>>a;
      V.emplace_back(a,i);
      mx = max(mx, a);
   }
   sort(V.begin(), V.end(), greater<>());
   for(int i=0;i<K;i++) cout<<V[i].second<<' ';
   vector<int> T;
   for(int i=K;i<N;i++){
      if(V[i].first == mx) T.push_back(V[i].second);
   }
   for(int i=0;i<K;i++){
      if(V[i].first == mx) T.push_back(V[i].second);
   }
   M -= K;
   while(M > 0){
      int g = min(int(T.size()), M);
      for(int i=0;i<g;i++)   cout<<T[i]<<' ';
      M -= g;
   }
   
}