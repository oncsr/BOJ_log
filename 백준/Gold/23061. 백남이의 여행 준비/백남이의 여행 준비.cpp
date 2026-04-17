#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    int dp[1000001]{};
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=1000000-a;j>0;j--){
            if(!dp[j])  continue;
            dp[j+a] = max(dp[j+a], dp[j] + b);
        }
        dp[a] = max(dp[a], b);
    }

    for(int i=1;i<=1000000;i++) dp[i] = max(dp[i], dp[i-1]);
    int ans = 0;
    ld mx = -1;
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        ld v = (ld)dp[a] / (ld)a;
        if(v > mx)  mx = v, ans = i;
    }
    cout<<ans;

}