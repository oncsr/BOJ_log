#include <bits/stdc++.h>
using namespace std;

int root[1001]{};
vector<vector<pair<int, int>>> V(1001);

int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

int mx = 0, d = 0;
void dfs(int n, int p, int x){
    if(n == d)  {mx = x;return;}
    for(auto [i,c] : V[n]){
        if(i == p)  continue;
        dfs(i,n,max(x,c));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    iota(root, root+N+1, 0);

    vector<tuple<int, int, int>> E;
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        E.emplace_back(c,a,b);
    }
    sort(E.begin(), E.end());
    int S = 0;
    for(auto [c,a,b]:E){
        int x = find(a), y = find(b);
        if(x==y)    continue;
        S += c;
        root[x] = y;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    int Q;
    for(cin>>Q;Q--;){
        int a,b;
        cin>>a>>b;
        d = b;
        mx = 0;
        dfs(a,0,0);
        cout<<S-mx<<'\n';
    }

}