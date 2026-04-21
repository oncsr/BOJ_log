#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n, m;
    vector<vector<int>> dist(401, vector<int>(401, 1e9));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    int ans = 1e9;
    for(int i=1;i<=n;i++)   ans = min(ans, dist[i][i]);
    cout<<(ans==1e9?-1:ans);

}