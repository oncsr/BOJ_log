#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, K, A[10001]{};
   cin>>N>>K;
   for(int i=1;i<=N;i++)   cin>>A[i];
   int cnt = 0;
   for(int last=N;last>1;last--){
      int i = max_element(A, A+last+1) - A;
      if(last != i)  swap(A[i], A[last]), cnt++;
      if(cnt == K)   return cout<<A[i]<<' '<<A[last], 0;
   }
   cout<<-1;

}