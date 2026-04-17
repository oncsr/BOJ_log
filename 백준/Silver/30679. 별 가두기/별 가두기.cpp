#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    int arr[101][101]{};
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> ans;
    for(int k=1;k<=N;k++){
        int x = k, y = 1, dir = 0;
        int vis[101][101][4]{};
        while(!vis[x][y][dir]){
            vis[x][y][dir]++;
            int v = arr[x][y];
            x += dx[dir] * v;
            y += dy[dir] * v;
            dir = (dir+1)%4;
            if(x < 1 || x > N || y < 1 || y > M)    break;

        }
        if(x < 1 || x > N || y < 1 || y > M)    continue;
        ans.push_back(k);

    }
    cout<<ans.size()<<'\n';
    for(int i:ans)  cout<<i<<' ';

}