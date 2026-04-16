#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin>>N>>Q;
    vector<vector<int>> V(N+1);
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    vector<int> par(N+1), vis(N+1);
    
    queue<pair<int, int>> q;
    q.emplace(1,0);
    vis[1]++;
    while(!q.empty()){
        auto [n,p] = q.front();
        q.pop();
        par[n] = p;
        for(int i:V[n]){
            if(i == p || vis[i])  continue;
            q.emplace(i,n);
            vis[i]++;
        }
    }

    vector<ll> X(N+1);
    for(int i=1;i<=N;i++)   cin>>X[i];
    for(;Q--;){
        ll o,u,x;
        cin>>o>>u;
        if(o == 2)  cout<<X[u]<<'\n';
        else{
            cin>>x;
            queue<pair<int, ll>> qq;
            qq.emplace(u,x);
            while(!qq.empty()){
                auto [n,t] = qq.front();
                qq.pop();
                ll d = min(t, X[n]);
                t -= d;
                X[n] += d;
                if(n == 1){
                    if(V[n].empty() || t/V[n].size() < 1)   continue;
                    t /= V[n].size();
                }
                else{
                    if(V[n].size() == 1 || t/(V[n].size()-1) < 1)   continue;
                    t /= (V[n].size()-1);
                }
                for(int i:V[n]){
                    if(i == par[n]) continue;
                    qq.emplace(i,t);
                }
            }
        }
    }


}