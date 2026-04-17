#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K, s, e;
    cin>>N>>M>>K>>s>>e;

    vector<vector<pair<int, int>>> V(1001);
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    vector<vector<int>> D(1001, vector<int>(1000, -1));
    D[s][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
    Q.emplace(0,s,0);
    while(!Q.empty()){
        auto [dist, now, cross] = Q.top();
        Q.pop();
        if(dist > D[now][cross])    continue;
        for(auto &[next, cost] : V[now]){
            int res = dist + cost;
            if(D[next][cross+1] == -1 || D[next][cross+1] > dist + cost){
                D[next][cross+1] = dist + cost;
                Q.emplace(D[next][cross+1], next, cross+1);
            }
        }
    }
    
    int S = 0;
    int ans = 1e9;
    for(int i=0;i<1000;i++){
        if(D[e][i] == -1)   continue;
        ans = min(ans, D[e][i] + i*S);
    }
    cout<<ans<<'\n';
    for(;K--;){
        int a;
        cin>>a;
        S += a;
        ans = 1e9;
        for(int i=0;i<1000;i++){
            if(D[e][i] == -1)   continue;
            ans = min(ans, D[e][i] + i*S);
        }
        cout<<ans<<'\n';
    }

}