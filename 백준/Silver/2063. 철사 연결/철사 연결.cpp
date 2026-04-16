#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int K;
   for(cin>>K;K--;){
      int N;
      cin>>N;
      ll arr[20]{};
      for(int i=0;i<N;i++){
         string a;
         cin>>a;
         string o = "";
         ll g = 0;
         for(int j=0;j<a.size();j++){
            if(a[j] == '.'){
               g = stoll(o) * 2000;
               o = "";
               for(int k=1;k<=3 && j+k < a.size();k++)   o += a[j+k];
               while(o.size()<3) o += "0";
               g += stoll(o) * 2;
               break;
            }
            else  o += a[j];
         }
         arr[i] = g;
      }
      sort(arr, arr+N);
      if(N == 1)  cout<<"NO\n";
      else{
         bool f = 0;
         for(int i=0;i<N-1;i++){
            if(arr[i] == arr[i+1]){
               cout<<"YES\n";
               f = 1;
               break;
            }
         }
         if(!f){
            ll s = arr[0] + arr[1];
            for(int i=2;i<N;i++){
               if(arr[i] <= s){
                  cout<<"YES\n";
                  f = 1;
                  break;
               }
               s += arr[i];
            }
            if(!f)   cout<<"NO\n";
         }

      }

   }

}