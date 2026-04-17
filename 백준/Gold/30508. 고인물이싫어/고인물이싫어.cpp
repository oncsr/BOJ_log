#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, H, W;
    cin>>N>>M>>H>>W;
    int arr[1001][1001]{};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }

    int vis[1001][1001]{};
    int K;
    cin>>K;
    queue<pair<int, int>> Q;
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        Q.push({a,b});
        vis[a][b]++;
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>0&&xx<=N&&yy>0&&yy<=M&&!vis[xx][yy]&&arr[xx][yy]>=arr[x][y]){
                Q.push({xx,yy});
                vis[xx][yy]++;
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            vis[i][j] += vis[i-1][j] + vis[i][j-1] - vis[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i=H;i<=N;i++){
        for(int j=W;j<=M;j++){
            if(vis[i][j] - vis[i-H][j] - vis[i][j-W] + vis[i-H][j-W] == H*W)    ans++;
        }
    }
    cout<<ans;

}