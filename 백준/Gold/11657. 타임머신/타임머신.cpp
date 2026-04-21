#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    vector<tuple<int, int, ll>> E;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        E.push_back({a,b,c});
    }
    vector<ll> dist(501, 1e18);
    bool cy = 0;
    dist[1] = 0;
    for(int i=0;i<n;i++){
        for(auto e:E){
            int a = get<0>(e), b = get<1>(e);
            ll c = get<2>(e);
            if(dist[a] == 1e18) continue;
            if(dist[a] + c < dist[b]){
                dist[b] = dist[a]+c;
                if(i == n-1)    cy = 1;
            }
        }
    }
    if(cy){cout<<-1;return 0;}
    for(int i=2;i<=n;i++)   cout<<(dist[i] == 1e18?-1:dist[i])<<'\n';
}