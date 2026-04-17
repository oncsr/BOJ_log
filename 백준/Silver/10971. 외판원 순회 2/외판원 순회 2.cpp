#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int W[16][16]{};
vector<vector<int>> dist(16, vector<int>(1<<16));

int dp(int n, int k){
    if(dist[n][k])  return dist[n][k];
    int g = k - (1<<n);
    for(int i=0;(1<<i)<=g;i++){
        if(!(g&(1<<i))) continue;
        if(!dist[i][g]) dist[i][g] = dp(i,g);
        if(!dist[n][k]) dist[n][k] = dist[i][g] + W[i][n];
        else    dist[n][k] = min(dist[n][k], dist[i][g] + W[i][n]);
    }
    return dist[n][k];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>W[i][j];
            if(!W[i][j])    W[i][j] = 1e8;
        }
    }
    int ans = 1e8;
    for(int i=0;i<N;i++){
        dist = vector<vector<int>>(16, vector<int>(1<<16, 0));
        for(int j=0;j<N;j++)    dist[j][1<<j] = W[i][j];
        int g = dp(i,(1<<N)-1);
        if(!g)  continue;
        ans = min(ans, g);
    }
    cout<<ans;

}