#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, W, P;
    cin>>N>>W>>P;
    vector<vector<pair<int,int>>> V(101);
    for(int a,b,c;W--;){
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    
    for(int p,q;P--;){
        cin>>p>>q;
        queue<pair<int,int>> Q;
        vector<int> vis(101);
        Q.emplace(p,0);
        vis[p]++;
        while(!Q.empty()){
            auto [n,t] = Q.front();Q.pop();
            if(n == q)    {cout<<t<<'\n';break;}
            for(auto [i,c]:V[n]){
                if(vis[i])    continue;
                vis[i]++;
                Q.emplace(i,t+c);
            }
        }
    }
    
}