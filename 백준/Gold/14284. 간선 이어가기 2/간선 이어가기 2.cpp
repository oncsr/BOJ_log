#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m,s,t;
    cin>>n>>m;
    vector<vector<pair<int, int>>> V(n+1);
    for(;m--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    cin>>s>>t;
    vector<int> D(n+1,-1);
    D[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.emplace(0,s);
    while(!Q.empty()){
        auto [dist, now] = Q.top();
        Q.pop();
        if(dist > D[now])   continue;
        for(auto [next, cost] : V[now]){
            if(D[next] == -1 || D[next] > dist + cost){
                D[next] = dist + cost;
                Q.emplace(D[next], next);
            }
        }
    }
    cout<<D[t];

}