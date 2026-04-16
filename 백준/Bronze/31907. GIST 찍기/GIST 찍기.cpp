#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    vector<vector<char>> V(3*N, vector<char>(4*N, '.'));
    for(int i=0;i<N;i++)    for(int j=0;j<N;j++) V[i][j] = 'G';
    for(int i=N;i<2*N;i++)  for(int j=N;j<2*N;j++)   V[i][j] = 'I';
    for(int i=2*N;i<3*N;i++)  for(int j=2*N;j<3*N;j++)   V[i][j] = 'S';
    for(int i=N;i<2*N;i++)  for(int j=3*N;j<4*N;j++)   V[i][j] = 'T';
    for(int i=0;i<3*N;i++){
        for(int j=0;j<4*N;j++)  cout<<V[i][j];
        cout<<'\n';
    }
    
}