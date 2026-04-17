#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1001][400]{}, N, mod = 1e18;

ll D(int n, int k){
    if(dp[n][k])    return dp[n][k];
    return dp[n][k] = (D(n-1,k) + D(n,k+1)) % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        int k = (double)i/3.14159265358979323;
        dp[i][k] = 1;
    }
    cout<<D(N,0);
}