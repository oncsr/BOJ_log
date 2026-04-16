#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int N;
  cin>>N;
  vector<tuple<int,int,int>> A(N);
  int id = 1;
  for(auto &[x,y,z]:A) cin>>x>>y, z = id++;
  sort(A.begin(), A.end());
  for(int i=1;i<N;i++) cout<<get<2>(A[i])<<' '<<get<2>(A[i-1])<<'\n';
  
}