#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> root;
    
public:
    DisjointSet(int sz) {
        root.resize(sz+1);
        iota(root.begin(), root.end(), 0);
    }

    int find(int x) { return x == root[x] ? x : root[x] = find(root[x]); }

    bool uni(int a, int b) {
        int x = find(a), y = find(b);
        if(x == y) return false;
        root[x] = y;
        return true;
    }
};

int N, M;
int num = 0;
vector<tuple<int, int, int, int>> edges;
vector<vector<pair<int, int>>> tree;
vector<int> parent, depth, answer, edgeNum;

void dfs(int n, int p, int d) {
    parent[n] = p;
    depth[n] = d;
    for(auto [i,x]:tree[n]) if(i != p) {
        dfs(i,n,d+1);
        edgeNum[i] = x;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;

    edges.resize(M);
    tree.resize(N+1);
    parent.resize(N+1);
    depth.resize(N+1);
    edgeNum.resize(N+1);
    answer.resize(M);
    DisjointSet *ds = new DisjointSet(N);
    
    int idx = 0;
    for(auto &[a,b,c,x] : edges) {
        cin>>a>>b>>c;
        x = idx++;
        if(c) {
            tree[a].emplace_back(b, x);
            tree[b].emplace_back(a, x);
        }
    }    

    dfs(1,0,0);

    num = 1;
    for(auto [a,b,c,e] : edges) {
        if(!answer[e]) {
            if(c) {
                int child = parent[a] == b ? a : b;
                answer[edgeNum[child]] = num++;
                ds->uni(child, parent[child]);
            }
            else {
                int cnt = 0;

                vector<int> needs;
                int x = ds->find(a), y = ds->find(b);
                while(x != y) {
                    if(depth[x] > depth[y]) swap(x,y);
                    needs.push_back(y);
                    ds->uni(y, parent[y]);
                    x = ds->find(x), y = ds->find(y);
                    cnt++;
                }
                
                sort(needs.begin(), needs.end(), [](int p, int q) -> bool {
                    return edgeNum[p] < edgeNum[q];
                });

                answer[e] = num + cnt;
                for(int i:needs) answer[edgeNum[i]] = num++;
                num++;
            }
        }
    }

    for(int i:answer) cout<<i<<' ';

}