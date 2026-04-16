#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M,p,q,r,s;
    cin>>N>>M>>p>>q>>r>>s;
    
    int arr[1002][1002]{}, vis[1002][1002][2]{}, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)  cin>>arr[i][j];

    queue<tuple<int,int,int,int>> Q;
    Q.emplace(p,q,0,0);
    vis[p][q][0]++;
    while(!Q.empty()){
        auto [x,y,k,t]=Q.front();Q.pop();
        if(x==r&&y==s)  return cout<<t,0;
        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<1 || xx>N || yy<1 || yy>M) continue;
            int nk = k+arr[xx][yy];
            if(nk > 1 || vis[xx][yy][nk])  continue;
            vis[xx][yy][nk]++;
            Q.emplace(xx,yy,nk,t+1);
        }
    }
    cout<<-1;

}