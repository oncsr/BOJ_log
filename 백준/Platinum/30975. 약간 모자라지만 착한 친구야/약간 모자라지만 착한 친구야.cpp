#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int P[16]{};
vector<vector<int>> edge(16, vector<int>(16, -1));

int dist[16][1<<16]{};

int dp(int n, int vis){
    if(dist[n][vis])  return dist[n][vis];
    if(!(vis&(1<<P[n]))) return 0;
    int g = vis - (1<<n);
    for(int i=1;(1<<i)<=g;i++){
        if(!(g&(1<<i)))  continue;
        if(edge[i][n] == -1)    continue;
        if(!dist[i][g]) dist[i][g] = dp(i,g);
        if(!dist[i][g]) continue;
        if(!dist[n][vis])   dist[n][vis] = dist[i][g] + edge[i][n];
        else    dist[n][vis] = min(dist[n][vis], dist[i][g] + edge[i][n]);
    }
    return dist[n][vis];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++)   cin>>P[i];
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        if(edge[a][b] == -1)    edge[a][b] = c;
        else    edge[a][b] = min(edge[a][b], c);
    }
    for(int i=1;i<=N;i++){
        if(edge[N+1][i] == -1) continue;
        if(P[i] != i)   continue;
        dist[i][1<<i] = edge[N+1][i];
    }
    int ans = 1e5;
    for(int i=1;i<=N;i++){
        if(edge[i][N+1] == -1) continue;
        int g = dp(i, (1<<(N+1))-2);
        if(!g)  continue;
        ans = min(ans, g + edge[i][N+1]);
    }
    cout<<(ans >= 1e5 ? -1:ans);

}