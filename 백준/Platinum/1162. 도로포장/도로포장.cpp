#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin>>N>>M>>K;
    vector<vector<pair<int, ll>>> V(N+1);
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    vector<vector<ll>> D(N+1, vector<ll>(K+1, -1));
    D[1][0] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> Q;
    Q.emplace(0,1,0);
    while(!Q.empty()){
        auto [dist, now, p] = Q.top();
        Q.pop();
        if(dist > D[now][p])    continue;
        for(auto [next, cost] : V[now]){
            if(D[next][p] == -1 || D[next][p] > dist + cost){
                D[next][p] = dist + cost;
                Q.emplace(D[next][p], next, p);
            }
            if(p == K)  continue;
            if(D[next][p+1] == -1 || D[next][p+1] > dist){
                D[next][p+1] = dist;
                Q.emplace(D[next][p+1], next, p+1);
            }
        }
    }
    ll ans = 1e18;
    for(int i=0;i<=K;i++){
        if(D[N][i] == -1)   continue;
        ans = min(ans, D[N][i]);
    }
    cout<<ans;

}