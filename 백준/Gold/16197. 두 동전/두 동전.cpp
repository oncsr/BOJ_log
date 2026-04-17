#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin>>N>>M;
    char arr[21][21]{};

    int vis[22][22][22][22]{};
    int a = -1, b, aa, bb;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'o'){
                if(a == -1) a = i, b = j;
                else    aa = i, bb = j;
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    vis[a][b][aa][bb]++;
    vis[aa][bb][a][b]++;
    queue<tuple<int, int, int, int, int>> Q;
    Q.emplace(a,b,aa,bb,0);
    while(!Q.empty()){
        auto [x, y, xx, yy, t] = Q.front();
        Q.pop();
        if(t > 10)  {cout<<-1;return 0;}
        int drop = 0;
        if(x < 1 || y < 1 || x > N || y > M)  drop++;
        if(xx < 1 || yy < 1 || xx > N || yy > M)  drop++;
        if(drop > 1)    continue;
        if(drop == 1){
            cout<<t;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i], nxx = xx+dx[i], nyy = yy+dy[i];
            if(arr[nx][ny] == '#')  nx-=dx[i], ny-=dy[i];
            if(arr[nxx][nyy] == '#')    nxx-=dx[i], nyy-=dy[i];
            if(!vis[nx][ny][nxx][nyy]){
                vis[nx][ny][nxx][nyy]++;
                vis[nxx][nyy][nx][ny]++;
                Q.emplace(nx,ny,nxx,nyy,t+1);
            }
        }
    }
    cout<<-1;

}