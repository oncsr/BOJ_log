#include <bits/stdc++.h>
using namespace std;

int N, dp[10001][2]{}, arr[10001]{};
vector<vector<int>> V(10001);
vector<int> ans;

void dfs(int n, int p){
    dp[n][1] = arr[n];
    for(int i:V[n]){
        if(i == p)  continue;
        dfs(i, n);
        dp[n][1] += dp[i][0];
        dp[n][0] += max(dp[i][0], dp[i][1]);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(1, 0);
    cout<<max(dp[1][0], dp[1][1]);

}