#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);
   
   int K, h;
   cin>>K;
   vector<char> V(2*K);
   for(char &i:V) cin>>i;
   cin>>h;

   vector<vector<int>> A(2, vector<int>(2));
   A[h>>1][h&1] = 1;

   for(int i=2*K-1;i>=0;i--){
      if(V[i] == 'R' || V[i] == 'L'){
         vector<vector<int>> N(A.size(), vector<int>(2 * A[0].size()));
         if(V[i] == 'R'){
            for(int i=0;i<A.size();i++){
               reverse(A[i].begin(), A[i].end());
            }
         }
         for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
               N[i][j] = A[i][j];
               int k = A[0].size() * 2 - 1 - j;
               N[i][k] = A[i][j];
            }
         }
         A = N;
      }
      else{
         vector<vector<int>> N(A.size() * 2, vector<int>(A[0].size()));
         if(V[i] == 'D'){
            for(int i=A.size();i<A.size() * 2;i++){
               for(int j=0;j<A[0].size();j++){
                  N[i][j] = A[i-A.size()][j];
                  int k = A.size() * 2 - 1 - i;
                  N[k][j] = A[i-A.size()][j];
               }
            }
         }
         else{
            for(int i=0;i<A.size();i++){
               for(int j=0;j<A[0].size();j++){
                  N[i][j] = A[i][j];
                  int k = A.size() * 2 - 1 - i;
                  N[k][j] = A[i][j];
               }
            }
         }
         A = N;
      }

   }

   for(int i=0;i<(1<<(K+1));i+=2){
      for(int j=0;j<(1<<(K+1));j+=2){
         if(A[i][j] == 1)  cout<<"0 ";
         else if(A[i][j+1])   cout<<"1 ";
         else if(A[i+1][j])   cout<<"2 ";
         else if(A[i+1][j+1]) cout<<"3 ";
      }
      cout<<'\n';
   }

}