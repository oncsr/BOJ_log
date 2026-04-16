#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F(ll n){
   ll g = log10(n), res = 0, c = 100;
   if(g >= 1)  res += 9;
   else  return n;
   for(int i=1;i<g;i++){
      res += (c*9/10) * (i+1);
      c *= 10;
   }
   c /= 10;
   return res + (n - c + 1) * (g+1);
}

ll G(ll n){
   return F(n) + n - (n/4);
}

int main(){
   cin.tie(0)->sync_with_stdio(0);


   ll K;
   for(cin>>K;K;cin>>K){
      ll s = 1, e = 1e15, m = (s+e)>>1;
      while(s < e){
         if(K > G(m))   s = m+1;
         else  e = m;
         m = (s+e)>>1;
      }
      s = (m-1 == 0 ? 0 : G(m-1)) + 1, e = G(m);
      string w = to_string(m);
      if(K == e){
         if((m%4)%2 == 1)  cout<<2;
         else if(m%4 == 2) cout<<0;
         else  cout<<w[K-s];
      }
      else  cout<<w[K-s];
      cout<<'\n';
   }

}