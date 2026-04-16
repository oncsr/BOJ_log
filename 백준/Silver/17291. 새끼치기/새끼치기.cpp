#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int N;
   cin>>N;
   int arr[21][4]{};
   arr[1][2] = 1;
   for(int i=1;i<N;i++){
      for(int j=0;j<4;j++){
         int life = 3 - ((i+1)&1);
         arr[i+1][life] += arr[i][j];
         if(j) arr[i+1][j-1] += arr[i][j];
      }
   }
   int s = 0;
   for(int i=0;i<4;i++) s += arr[N][i];
   cout<<s;

}