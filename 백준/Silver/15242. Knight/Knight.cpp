#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    char a, b;
    int c, d;
    cin>>a>>c>>b>>d;
    int e = a - 'a' + 1, f = b - 'a' + 1;

    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    int vis[9][9]{};
    queue<tuple<int, int, int>> Q;
    vis[e][c]++;
    Q.emplace(e,c,0);
    while(!Q.empty()){
        auto [x, y, t] = Q.front();
        Q.pop();
        if(x == f && y == d){cout<<t;return 0;}
        for(int i=0;i<8;i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 1 && xx <= 8 && yy >= 1 && yy <= 8 && !vis[xx][yy]){
                Q.emplace(xx, yy, t+1);
                vis[xx][yy]++;
            }
        }
    }

    
}