#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, A[5002][5002]{}, s=0;
    cin>>n>>m;
    for(int a,b,c;m--;A[a][b]=max(A[a][b],c+1)) cin>>a>>b>>c;
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++){
        int v=A[i][j];
        if(v) s++;
        A[i+1][j]=max(A[i+1][j],v-1);
        A[i+1][j+1]=max(A[i+1][j+1],v-1);
    }
    cout<<s;

}