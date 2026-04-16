#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, arr[15]{};
   cin>>N;
   for(int i=0;i<N;i++) cin>>arr[i];
   vector<vector<int>> D(1<<N, vector<int>(2, -1));
   D[0][0] = 0;
   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
   Q.emplace(0,0,0);
   while(!Q.empty()){
      auto [d, n, k] = Q.top();
      Q.pop();
      if(d > D[n][k])   continue;
      for(int i=0;i<N;i++){
         if(bool((1<<i) & n) != k)  continue;
         int d1 = d + arr[i], n1 = n^(1<<i);
         if(D[n1][k^1] == -1 || D[n1][k^1] > d1){
            D[n1][k^1] = d1;
            Q.emplace(d1, n1, k^1);
         }
         for(int j=0;j<i;j++){
            if(bool((1<<j) & n) != k)  continue;
            if(arr[i] == arr[j]) continue;
            int d2 = d + max(arr[i], arr[j]), n2 = n ^ (1<<i) ^ (1<<j);
            if(D[n2][k^1] == -1 || D[n2][k^1] > d2){
               D[n2][k^1] = d2;
               Q.emplace(d2, n2, k^1);
            }
         }
      }
   }
   cout<<D[(1<<N)-1][1];

}