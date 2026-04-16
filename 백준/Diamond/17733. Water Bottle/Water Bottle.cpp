#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int N, M, P, Q;
char arr[2000][2000]{};
int dist[2000][2000]{}, num[2000][2000]{};
int root[200001]{};
vector<tuple<int, int, int>> edges;
vector<vector<pair<int, int>>> v(200001);
int par[200001][18]{}, val[200001][18]{};
int dep[200001]{};
bitset<200001> vis;

int find(int x) { return x == root[x] ? x : root[x]=find(root[x]); }

void dfs(int n, int p, int d) {
    par[n][0] = p, dep[n] = d;
    vis[n] = 1;
    for(auto [i,c] : v[n]) if(i != p) {
        dfs(i,n,d+1);
        val[i][0] = c;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>P>>Q;
    iota(root, root+P+1, 0);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>arr[i][j];

    queue<tuple<int, int, int, int>> q;

    for(int i=1,a,b;i<=P;i++) {
        cin>>a>>b;
        num[--a][--b] = i;
        q.emplace(a,b,0,i);
    }

    while(!q.empty()) {
        auto [x,y,d,n] = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if(xx<0 || xx>=N || yy<0 || yy>=M || arr[xx][yy] == '#') continue;
            if(num[xx][yy]) {
                if(num[xx][yy] != n) {
                    edges.emplace_back(dist[xx][yy] + d, num[xx][yy], n);
                }
            }
            else {
                q.emplace(xx,yy,dist[xx][yy] = d+1, num[xx][yy] = n);
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(auto [c,a,b] : edges) {
        int x = find(a), y = find(b);
        if(x == y) continue;
        root[x] = y;
        v[a].emplace_back(b,c);
        v[b].emplace_back(a,c);
    }

    for(int i=1;i<=P;i++) if(!vis[i]) dfs(i,0,0);

    for(int k=1;k<18;k++) for(int i=1;i<=P;i++) {
        par[i][k] = par[par[i][k-1]][k-1];
        val[i][k] = max(val[i][k-1], val[par[i][k-1]][k-1]);
    }

    for(int a,b;Q--;) {
        cin>>a>>b;
        if(find(a) != find(b)) {
            cout<<"-1\n";
            continue;
        }
        int res = 0;

        int diff = abs(dep[a]-dep[b]);
        for(int k=0;k<18;k++) if(diff & (1<<k)) {
            if(dep[a] > dep[b]) {
                res = max(res, val[a][k]);
                a = par[a][k];
            }
            else {
                res = max(res, val[b][k]);
                b = par[b][k];
            }
        }

        for(int k=17;k>=0;k--) if(par[a][k] != par[b][k]) {
            res = max({res, val[a][k], val[b][k]});
            a = par[a][k], b = par[b][k];
        }
        
        if(a != b) res = max({res, val[a][0], val[b][0]});

        cout<<res<<'\n';
    }

}