#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   string a, b;
   cin>>a;
   int N, l=0, o=0, v=0, e=0;
   for(char i:a){
      l += i == 'L';
      o += i == 'O';
      v += i == 'V';
      e += i == 'E';
   }
   int mx = -1;
   string ans = "";
   for(cin>>N;N--;){
      cin>>b;
      int L=l, O=o, V=v, E=e;
      for(char i:b){
         L += i == 'L';
         O += i == 'O';
         V += i == 'V';
         E += i == 'E';
      }
      int res = (L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E) % 100;
      if(res > mx || (res == mx && b < ans))  mx = res, ans = b;
   }
   cout<<ans;

}