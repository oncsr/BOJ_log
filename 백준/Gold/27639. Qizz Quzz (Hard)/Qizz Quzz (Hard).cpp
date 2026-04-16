#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int T;
   for(cin>>T;T--;){
      int N;
      cin>>N;
      vector<string> arr(N+1);
      vector<string> A(N+1);
      for(int i=1;i<=N;i++)   cin>>A[i];

      int i = 1;
      for(;i<=N;i++){
         string a = A[i];
         string made = "";
         for(int j=1;j<i;j++){
            if(i%j)  continue;
            made += arr[j];
         }
         if(made == ""){
            if(a == to_string(i))   continue;
            bool num = 0;
            for(char j:a){
               if('0' <= j && j <= '9')   num = 1;
            }
            if(num)  break;
            if(a.size() > 25) break;
            arr[i] = a;
         }
         else{
            if(a == made)  continue;
            if(a.size() < made.size() || a.substr(0,made.size()) != made)  break;
            string b = a.substr(made.size(), a.size() - made.size());
            bool num = 0;
            for(char j:b){
               if('0' <= j && j <= '9')   num = 1;
            }
            if(num)  break;
            if(b.size() > 25) break;
            arr[i] = b;
         }
      }
      cout<<--i<<'\n';
   }

}