#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    int S = 0, A[301][301]{};
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
        int a;
        cin>>a;
        S += a-50;
        A[i][j] = 50-a;
    }

    int mx = -2e9;
    for(int i=1;i<=N;i++){
        int B[301]{};
        for(int j=i;j<=N;j++){
            int res = -2e9;
            for(int k=1;k<=N;k++){
                B[k] += A[j][k];
                res = max(B[k], res + B[k]);
                mx = max(mx, res);
            }
        }
    }
    cout<<S+mx;

}