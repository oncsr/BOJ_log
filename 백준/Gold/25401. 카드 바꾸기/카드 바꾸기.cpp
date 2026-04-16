#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int N;
   cin>>N;
   vector<ll> arr(N);
   for(ll &i:arr) cin>>i;

   int ans = 1e9;
   for(int i=0;i<N;i++){
      int diff = 0;
      for(int j=0;j<N;j++) diff += (arr[i] != arr[j]);
      ans = min(ans, diff);
      for(int j=i+1;j<N;j++){
         if((arr[j] - arr[i])%(j-i))   continue;
         diff = 0;
         ll d = (arr[j] - arr[i]) / (j-i);
         ll a = arr[i] - i*d;
         for(int k=0;k<N;k++) diff += (arr[k] != a + k*d);
         ans = min(ans, diff);
      }
   }
   cout<<ans;

}