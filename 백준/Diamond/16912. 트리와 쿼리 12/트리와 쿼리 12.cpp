#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> root, rank;
    stack<tuple<int, int, int>> works;
public:
    DisjointSet(int sz) {
        root.resize(sz+1);
        iota(root.begin(), root.end(), 0);
        rank.resize(sz+1);
        fill(rank.begin(), rank.end(), 1);
    }

    int find(int x) { return x == root[x] ? x : find(root[x]); }

    void uni(int a, int b) {
        int x = find(a), y = find(b);
        if(x == y) {
            works.emplace(-1,-1,-1);
            return;
        }
        if(rank[x] > rank[y]) swap(x, y);
        works.emplace(x, y, rank[x]);
        rank[y] += rank[x];
        root[x] = y;
    }

    void rollback() {
        auto [x, y, r] = works.top();
        works.pop();
        if(x == -1) return;
        rank[y] -= r;
        root[x] = x;
    }
};

DisjointSet *ds;
int N, Q;
map<pair<int, int>, int> mp;
vector<vector<pair<int, int>>> ev;
vector<vector<pair<int, int>>> chk;

void upt(int s, int e, int l, int r, int a, int b, int n) {
    if(l>r || l>e || r<s) return;
    if(l<=s && e<=r) {
        ev[n].emplace_back(a,b);
        return;
    }
    int m = (s+e)>>1;
    upt(s,m,l,r,a,b,n<<1);
    upt(m+1,e,l,r,a,b,n<<1|1);
}

void cle(int s, int e, int n) {
    for(auto [x,y] : ev[n]) ds->uni(x,y);
    if(s == e) {
        for(auto [x,y] : chk[s]) {
            cout<<(ds->find(x) == ds->find(y) ? 1 : 0)<<'\n';
        }
        for(auto [x,y] : ev[n]) ds->rollback();
        return;
    }
    int m = (s+e)>>1;
    cle(s,m,n<<1);
    cle(m+1,e,n<<1|1);
    for(auto [x,y] : ev[n]) ds->rollback();
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>N>>Q;
    ds = new DisjointSet(N);
    chk.resize(Q+1);
    ev.resize(Q*4);
    for(int i=1,a,b,c;i<=Q;i++) {
        cin>>a>>b>>c;
        int x = min(b,c), y = max(b,c);
        if(a == 1) mp[{x,y}] = i;
        else if(a == 2) {
            int t = mp[{x,y}];
            upt(1,Q,t,i,x,y,1);
            mp.erase({x,y});
        }
        else {
            chk[i].emplace_back(x,y);
        }
    }

    for(auto [a,b] : mp) upt(1,Q,b,Q,a.first,a.second,1);

    cle(1,Q,1);

}