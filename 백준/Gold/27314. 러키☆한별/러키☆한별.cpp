#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin>>N>>M;
    vector<vector<int>> arr(N, vector<int>(M));
    vector<pair<int, int>> people;
    pair<int, int> start;
    int num = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char a;
            cin>>a;
            if(a == '#')    arr[i][j] = ++num;
            else if(a == 'X')   arr[i][j] = -1;
            else if(a == 'P')   people.emplace_back(i,j);
            else if(a == 'H')   start = make_pair(i,j);
        }
    }
    vector<vector<int>> ex(num + 1);

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(auto [p, q] : people){
        vector<vector<int>> vis(N, vector<int>(M));
        vis[p][q]++;
        queue<tuple<int, int, int>> Q;
        Q.emplace(p, q, 0);
        while(!Q.empty()){
            auto [x, y, t] = Q.front();
            Q.pop();
            if(arr[x][y] > 0){
                ex[arr[x][y]].push_back(t);
            }
            for(int i=0;i<4;i++){
                int xx = x+dx[i], yy = y+dy[i];
                if(xx>=0&&xx<N&&yy>=0&&yy<M&&!vis[xx][yy]&&arr[xx][yy] != -1){
                    vis[xx][yy]++;
                    Q.emplace(xx,yy,t+1);
                }
            }
        }
    }
    for(int i=1;i<=num;i++) sort(ex[i].begin(), ex[i].end());

    vector<vector<int>> vis(N, vector<int>(M));
    queue<tuple<int, int, int>> Q;
    vis[start.first][start.second]++;
    Q.emplace(start.first, start.second, 0);
    int ans = 0;
    while(!Q.empty()){
        auto [x, y, t] = Q.front();
        Q.pop();
        if(arr[x][y] > 0){
            int v = upper_bound(ex[arr[x][y]].begin(), ex[arr[x][y]].end(), t) - ex[arr[x][y]].begin();
            ans = max(ans, v);
        }
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0&&xx<N&&yy>=0&&yy<M&&!vis[xx][yy]&&arr[xx][yy] != -1){
                vis[xx][yy]++;
                Q.emplace(xx,yy,t+1);
            }
        }
    }
    cout<<ans;

}