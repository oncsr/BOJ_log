#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    ll dp[31][31]{};
    for(int i=1;i<=N;i++)   for(int j=1;j<=N;j++){
        int a;
        cin>>a;
        dp[i][j] = a;
        if(i != 1)  dp[i][j] = max(dp[i][j], (dp[i-1][j] << 1LL) + a);
        if(j != 1)  dp[i][j] = max(dp[i][j], (dp[i][j-1] << 1LL) + a);
    }
    cout<<dp[N][N];
    
}