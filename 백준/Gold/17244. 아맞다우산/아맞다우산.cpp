#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin>>M>>N;
    char arr[52][52]{}, c = '0';
    int vis[52][52][32]{};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<tuple<int,int,int,int>> Q;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
        cin>>arr[i][j];
        if(arr[i][j] == 'X')    arr[i][j] = c++;
        if(arr[i][j] == 'S')    Q.emplace(i,j,0,0), vis[i][j][0]++;
    }
    int s = (1<<int(c-'0'))-1;
    while(!Q.empty()){
        auto [x,y,k,t] = Q.front();Q.pop();
        if(arr[x][y] == 'E' && k == s)  return cout<<t,0;
        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<1 || xx>N || yy<1 || yy>M || arr[xx][yy]=='#')  continue;
            int nk = k;
            if('0' <= arr[xx][yy] && arr[xx][yy] <= c) nk |= (1<<int(arr[xx][yy]-'0'));
            if(vis[xx][yy][nk]) continue;
            vis[xx][yy][nk]++;
            Q.emplace(xx,yy,nk,t+1);
        }
    }

}