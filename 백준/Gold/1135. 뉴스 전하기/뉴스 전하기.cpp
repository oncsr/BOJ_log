#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> V(51);
int dp[51]{};

void dfs(int n){
    vector<int> child;
    for(int i:V[n]){
        dfs(i);
        child.push_back(dp[i]);
    }
    if(child.empty())   return;
    sort(child.begin(), child.end(), greater<int>());
    int t = 1, mx = 0;
    for(int i:child)    mx = max(mx, i+(t++));
    dp[n] = mx;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(a == -1) continue;
        V[a].push_back(i);
    }
    dfs(0);

    cout<<dp[0];


}