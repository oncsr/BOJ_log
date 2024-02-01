#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int arr[100][100]{};
    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++)    for(int j=0;j<M;j++)    cin>>arr[i][j];

    int vis[100][100]{};
    queue<pair<int, int>> Q;
    vis[0][0]++;
    Q.emplace(0,0);
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    while(!Q.empty()){
        auto [x,y] = Q.front();
        Q.pop();
        arr[x][y] = -1;
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0&&xx<N&&yy>=0&&yy<M&&!vis[xx][yy]&&!arr[xx][yy]){
                vis[xx][yy]++;
                Q.emplace(xx,yy);
            }
        }
    }
    
    int cheese, ans = -1;
    do{
        ans++;
        cheese = 0;
        vector<pair<int, int>> V;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] != 1)  continue;
                cheese++;
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int x = i+dx[k], y = j+dy[k];
                    if(x>=0&&x<N&&y>=0&&y<M&&arr[x][y]==-1) cnt++;
                }
                if(cnt >= 2)    V.emplace_back(i,j);
            }
        }
        fill(vis[0], vis[0]+N*M, 0);
        for(auto [i,j] : V){
            arr[i][j] = -1;
            if(vis[i][j])   continue;
            vis[i][j]++;
            Q.emplace(i,j);
            while(!Q.empty()){
                auto [x,y] = Q.front();
                Q.pop();
                arr[x][y] = -1;
                for(int k=0;k<4;k++){
                    int xx = x+dx[k], yy = y+dy[k];
                    if(xx>=0&&xx<N&&yy>=0&&yy<M&&!vis[xx][yy]&&!arr[xx][yy]){
                        vis[xx][yy]++;
                        Q.emplace(xx,yy);
                    }
                }
            }
        }
    }while(cheese > 0);

    cout<<ans;

}