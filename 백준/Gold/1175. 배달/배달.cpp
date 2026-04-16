#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    int sx, sy;
    char gift = 'A';
    char arr[50][50]{};
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>arr[i][j];
        if(arr[i][j] == 'S')    sx = i, sy = j;
        else if(arr[i][j] == 'C')   arr[i][j] = ++gift;
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int D[50][50][4][4]{};
    queue<tuple<int, int, int, int, int>> Q;
    for(int i=0;i<4;i++){
        int x = sx+dx[i], y = sy+dy[i];
        if(x<0 || x>=N || y<0 || y>=M || arr[x][y] == '#')  continue;
        Q.emplace(x,y,arr[x][y]=='.'?0:arr[x][y]-'A',i,1);
    }
    while(!Q.empty()){
        auto [x,y,g,p,t] = Q.front();   Q.pop();
        if(g == 3) return cout<<t,0;
        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<0 || xx>=N || yy<0 || yy>=M || arr[xx][yy] == '#' || i == p)  continue;
            int ng = g;
            if(arr[xx][yy] != 'S' && arr[xx][yy] != '.')    ng |= (arr[xx][yy] - 'A');
            if(D[xx][yy][ng][i])    continue;
            D[xx][yy][ng][i] = t+1;
            Q.emplace(xx,yy,ng,i,t+1);
        }
    }
    cout<<-1;

}