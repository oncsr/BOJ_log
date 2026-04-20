#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n, m;
    cin>>n>>m;
    char arr[500][500]{};
    int dist[500][500]{}, vis1[500][500]{};
    ii S, E;
    queue<tuple<int, int, int>> Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == '+')    vis1[i][j]++, Q.push({i,j,0}), dist[i][j] = 0;
            if(arr[i][j] == 'V')    S = make_pair(i,j);
            if(arr[i][j] == 'J')    E = make_pair(i,j);
        }
    }
    while(!Q.empty()){
        int x = get<0>(Q.front()), y = get<1>(Q.front()), c = get<2>(Q.front());
        Q.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis1[xx][yy]){
                vis1[xx][yy]++;
                dist[xx][yy] = c+1;
                Q.push({xx,yy,c+1});
            }
        }
    }
    int ans = 1e9;
    priority_queue<tuple<int, int, int>> PQ;
    int vis[500][500]{};
    PQ.push({dist[S.first][S.second], S.first, S.second });
    vis[S.first][S.second]++;
    while(!PQ.empty()){
        int x = get<1>(PQ.top()), y = get<2>(PQ.top()), c = get<0>(PQ.top());
        ans = min(ans, c);
        if(make_pair(x,y) == E){
            cout<<ans;
            return 0;
        }
        PQ.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]){
                vis[xx][yy]++;
                PQ.push({dist[xx][yy],xx,yy});
            }
        }
    }

}