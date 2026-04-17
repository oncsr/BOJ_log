#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

vector<vector<pair<int, ll>>> V(300001);
vector<ll> dp(300001), sub(300001);
int N;

void dfs(int n, int p){
    sub[n] = 1;
    for(auto e:V[n]){
        int i = e.first, c = e.second;
        if(i == p)  continue;
        dfs(i, n);
        sub[n] += sub[i];
        dp[n] += dp[i] + c * sub[i];
    }
}

void dfs2(int n, int p){
    for(auto e:V[n]){
        int i = e.first, c = e.second;
        if(i == p)  continue;
        ll g = dp[i] + c * sub[i];
        dp[i] += dp[n] - g + c * (N - sub[i]);
        dfs2(i, n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    dfs(1,0);   dfs2(1,0);

    for(int i=1;i<=N;i++)   cout<<dp[i]<<'\n';


}