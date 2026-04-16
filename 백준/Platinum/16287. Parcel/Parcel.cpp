#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int W, N;
   cin>>W>>N;
   int arr[5001]{}, mx[400000]{};
   for(int i=1;i<=N;i++)   cin>>arr[i];
   for(int i=1;i<=N;i++)   for(int j=i+1;j<=N;j++) mx[arr[i]+arr[j]] = max(mx[arr[i]+arr[j]], i);
   for(int i=1;i<=N;i++)   for(int j=i+1;j<=N;j++){
      int need = W - arr[i] - arr[j];
      if(0 < need && need < 400000 && mx[need] > j)   return cout<<"YES", 0;
   }
   cout<<"NO";

}