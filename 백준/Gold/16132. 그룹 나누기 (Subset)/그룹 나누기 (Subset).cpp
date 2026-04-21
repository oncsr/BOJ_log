#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%4%3){cout<<0;return 0;}
    int k=n*(n+1)/4;
    long long dp[2501]{};
    for(int i=n;i>=1;i--){
        for(int j=k;j>=i;j--){
            dp[j] += dp[j-i];
        }
        dp[i] = 1;
    }
    cout<<dp[k]/2;
}