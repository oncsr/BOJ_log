#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int, ll>>> V;
vector<ll> D, S, E;

void dfs(int n, int p){
    S[n] = 1;
    for(auto [c,d] : V[n]){
        if(c == p)  continue;
        dfs(c,n);
        S[n] += S[c];
        D[n] += D[c] + d*S[c];
    }
}

void dfs2(int n, int p, ll cost){
    if(p != -1) E[n] = E[p] + D[p] - (D[n] + S[n] * cost) + (S[0] - S[n]) * cost;
    for(auto [c, d] : V[n]){
        if(c == p)  continue;
        dfs2(c,n,d);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    for(cin>>T;T--;){
        int N;
        cin>>N;
        V = vector<vector<pair<int, ll>>>(N);
        D = vector<ll>(N);
        S = vector<ll>(N);
        E = vector<ll>(N);
        for(int i=1;i<N;i++){
            int a,b,c;
            cin>>a>>b>>c;
            V[a].emplace_back(b,c);
            V[b].emplace_back(a,c);
        }
        dfs(0,-1);
        dfs2(0,-1,0);
        long double sum = 0;
        for(int i=0;i<N;i++)    sum += E[i] + D[i];
        sum /= 2.;
        sum /= N*(N-1)/2;
        cout.precision(10);
        cout<<fixed<<sum<<'\n';
    }

}