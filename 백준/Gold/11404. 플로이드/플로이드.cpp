#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dist(101, vector<int>(101, 1e9));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int i=1;i<=n;i++)   dist[i][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][k] > dist[j][i] + dist[i][k])    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   cout<<(dist[i][j]==1e9?0:dist[i][j])<<' ';
        cout<<'\n';
    }
}