#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int deg[1001]{}, dp[1001]{}, N, M;
    vector<vector<int>> R(1001);
    vector<vector<ii>> V(1001);
    for(cin>>N>>M;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        deg[b]++;
        V[a].push_back({b,c});
    }
    queue<pair<int, vector<int>>> Q;
    Q.push({1, {1}});
    while(!Q.empty()){
        int now = Q.front().first;
        vector<int> way = Q.front().second;
        Q.pop();
        for(auto e:V[now]){
            int next = e.first, cost = e.second;
            if(dp[next] < dp[now]+cost){
                dp[next] = dp[now]+cost;
                way.push_back(next);
                R[next] = way;
                way.pop_back();
            }
            if(!(--deg[next]))  Q.push({next, R[next]});
        }
    }
    cout<<dp[1]<<'\n';
    for(int i:R[1]) cout<<i<<' ';
    
}