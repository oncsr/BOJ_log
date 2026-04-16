#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   bitset<100001> B;
   int N;
   for(cin>>N;N--;){
      int a;
      cin>>a;
      B[a].flip();
   }
   cout<<(B.count() ? "koosaga" : "cubelover");
   
}