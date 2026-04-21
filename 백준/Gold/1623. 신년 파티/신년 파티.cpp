#include <bits/stdc++.h>
using namespace std;

int N, dp[200001][2]{}, arr[200001]{};
vector<vector<int>> V(200001);
vector<int> ans1, ans2;

void dfs(int n){
    dp[n][1] = arr[n];
    for(int i:V[n]){
        dfs(i);
        dp[n][1] += max(0, dp[i][0]);
        dp[n][0] += max({0, dp[i][0], dp[i][1]});
    }
}

void dfs2(int n, bool s, int id){
    if(s){
        if(id == 1) ans1.push_back(n);
        else    ans2.push_back(n);
    }
    for(int i:V[n]){
        if(s)   dfs2(i, 0, id);
        else{
            if(0 > max(dp[i][0], dp[i][1]) || dp[i][0] > dp[i][1])  dfs2(i, 0, id);
            else    dfs2(i, 1, id);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(int i=2;i<=N;i++){
        int a;
        cin>>a;
        V[a].push_back(i);
    }
    dfs(1);
    dfs2(1, 1, 1);
    dfs2(1, 0, 0);
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    cout<<dp[1][1]<<' '<<dp[1][0]<<'\n';
    for(int i:ans1) cout<<i<<' ';
    cout<<-1<<'\n';
    for(int i:ans2) cout<<i<<' ';
    cout<<-1;

}