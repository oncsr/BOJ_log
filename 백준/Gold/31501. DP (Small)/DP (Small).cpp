#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin>>N>>Q;
   int arr[3001]{};
   for(int i=1;i<=N;i++)   cin>>arr[i];
   int L[3001]{}, R[3001]{};
   for(int i=1;i<=N;i++){
      L[i] = 1;
      for(int j=1;j<i;j++){
         if(arr[i] > arr[j])  L[i] = max(L[i], L[j]+1);
      }
   }
   for(int i=N;i>=1;i--){
      R[i] = 1;
      for(int j=N;j>i;j--){
         if(arr[i] < arr[j])  R[i] = max(R[i], R[j]+1);
      }
   }
   
   for(;Q--;){
      int a;
      cin>>a;
      cout<<L[a] + R[a]-1<<'\n';
   }

}