#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, K, A[10001]{};
   cin>>N>>K;
   for(int i=1;i<=N;i++)   cin>>A[i];
   int cnt = 0;
   for(int last=N;last>1;last--){
      for(int i=1;i<last;i++){
         if(A[i] > A[i+1]) cnt++, swap(A[i], A[i+1]);
         if(cnt == K)   return cout<<A[i]<<' '<<A[i+1], 0;
      }
   }
   cout<<-1;

}