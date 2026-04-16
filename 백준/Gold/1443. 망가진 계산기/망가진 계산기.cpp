#include <bits/stdc++.h>
using namespace std;

int D, P, mx = -1;
void sol(int idx, int last, int res){
   if(idx == P){
      mx = max(mx, res);
      return;
   }
   for(int i=last;i<=9;i++){
      if(log10(res*i) >= D)   return;
      sol(idx+1, max(last,i), res*i);
   }
}

int main(){
   cin.tie(0)->sync_with_stdio(0);

   cin>>D>>P;
   sol(0,2,1);
   cout<<mx;

}