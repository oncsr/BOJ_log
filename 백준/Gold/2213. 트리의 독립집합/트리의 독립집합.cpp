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
        dp[n][1] += max(0, dp[i][0]);
        dp[n][0] += max({0, dp[i][0], dp[i][1]});
    }
}

void dfs2(int n, int p, bool s){
    if(s)   ans.push_back(n);
    for(int i:V[n]){
        if(i == p)  continue;
        if(s)   dfs2(i, n, 0);
        else{
            if(0 > max(dp[i][0], dp[i][1]) || dp[i][0] > dp[i][1])  dfs2(i, n, 0);
            else    dfs2(i, n, 1);
        }
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
    if(dp[1][1] > dp[1][0]) dfs2(1, 0, 1);
    else    dfs2(1, 0, 0);
    sort(ans.begin(), ans.end());
    cout<<max(dp[1][0], dp[1][1])<<'\n';
    for(int i:ans)  cout<<i<<' ';

}