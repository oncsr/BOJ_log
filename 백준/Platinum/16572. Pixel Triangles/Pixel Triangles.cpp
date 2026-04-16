#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    vector<vector<int>> A(2002, vector<int>(2002));
    for(cin>>N;N--;){
        int a,b,c;
        cin>>a>>b>>c;
        A[a][b]=max(A[a][b],c);
    }
    int s = 0;
    for(int i=1;i<=2000;i++)    for(int j=1;j<=2000;j++){
        if(A[i][j]) s++;
        A[i+1][j] = max(A[i+1][j],A[i][j]-1);
        A[i][j+1] = max(A[i][j+1],A[i][j]-1);
    }
    cout<<s;

}