#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;
using ll = long long;

ll D[2501][2501]{};
int N, M, C[2501]{};
vector<vector<pair<int,int>>> V(2501);
priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>, greater<>> Q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>C[i];
    for(int i=0,a,b,c;i<M;i++){
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    memset(D, -1, sizeof(D));
    Q.emplace(0,1,C[1]);
    D[1][C[1]] = 0;
    while(!Q.empty()){
        auto [t,n,v] = Q.top();
        Q.pop();
        for(auto [i,c]:V[n]){
            ll res = t + c*v;
            int x = min(v, C[i]);
            if(D[i][x] == -1 || D[i][x] > res){
                D[i][x] = res;
                Q.emplace(res,i,x);
            }
        }
    }
    ll ans = 1e18;
    for(int i=1;i<=2500;i++) if(D[N][i] != -1) ans = min(ans, D[N][i]);
    cout<<ans;
    
}