#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    vector<tuple<int, int, ll>> E;
    vector<vector<int>> G(101);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        E.push_back({a,b,-c});
        G[a].push_back(b);
    }
    vector<ll> dist(101, 1e18);
    vector<vector<int>> V(101);
    dist[1] = 0;
    V[1].push_back(1);
    for(int i=1;i<n;i++){
        for(auto e:E){
            int a = get<0>(e), b = get<1>(e);
            ll c = get<2>(e);
            if(dist[a] == 1e18) continue;
            if(dist[a]+c < dist[b]){
                V[b] = V[a];
                V[b].push_back(b);
                dist[b] = dist[a]+c;
            }
        }
    }
    bool cycle = 0;
    int start = 1;
    for(auto e:E){
        int a = get<0>(e), b = get<1>(e);
        ll c = get<2>(e);
        if(dist[a] == 1e18) continue;
        if(dist[a] + c < dist[b]){cycle = 1, start = b;break;}
    }
    bool nope = 0;
    if(cycle){
        int vis[101]{};
        queue<int> Q;
        Q.push(start);
        vis[start]++;
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            if(now == n){
                nope = 1;
                break;
            }
            for(int i:G[now]){
                if(vis[i])  continue;
                vis[i]++;
                Q.push(i);
            }
        }
    }


    if(nope || dist[n] == 1e18)    {cout<<-1;return 0;}

    for(auto i:V[n])    cout<<i<<' ';



}