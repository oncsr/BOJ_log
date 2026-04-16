#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin>>N>>Q;
   int arr[300001]{};
   for(int i=1;i<=N;i++)   cin>>arr[i];
   int L[300001]{}, R[300001]{};
   vector<int> V;
   for(int i=1;i<=N;i++){
      int p = lower_bound(V.begin(), V.end(), arr[i]) - V.begin();
      L[i] = p+1;
      if(p == V.size()) V.push_back(arr[i]);
      else  V[p] = arr[i];
   }
   V = vector<int>();
   for(int i=N;i>=1;i--){
      int p = lower_bound(V.begin(), V.end(), -arr[i]) - V.begin();
      R[i] = p+1;
      if(p == V.size()) V.push_back(-arr[i]);
      else  V[p] = -arr[i];
   }
   
   for(;Q--;){
      int a;
      cin>>a;
      cout<<L[a] + R[a]-1<<'\n';
   }

}