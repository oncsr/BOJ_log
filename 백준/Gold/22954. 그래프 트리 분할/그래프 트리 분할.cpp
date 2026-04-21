#include <bits/stdc++.h>
using namespace std;

int root[100001]{}, leaf;
vector<vector<pair<int, int>>> V(100001);
int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

void find_leaf(int n, int p){
    int child = 0;
    for(auto e:V[n]){
        int i = e.first;
        if(i == p)  continue;
        find_leaf(i, n);
        child++;
    }
    if(!child)  leaf = n;
}

vector<int> edges;
vector<int> nodes;

void dfs(int n, int p){
    nodes.push_back(n);
    for(auto e:V[n]){
        int i = e.first, g = e.second;
        if(i == p)  continue;
        edges.push_back(g);
        dfs(i, n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)   root[i] = i;
    int cnt = 0;
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        int x = find(a), y = find(b);
        if(x == y)  continue;
        root[x] = y;
        cnt++;
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }
    if(N <= 2 || cnt < N-2){
        cout<<-1;
        return 0;
    }

    if(cnt == N-2){
        dfs(1, 0);
        if(!(N&1) && nodes.size() == N/2){
            cout<<-1;
            return 0;
        }
        cout<<nodes.size()<<' '<<N-nodes.size()<<'\n';
        for(int i:nodes)    cout<<i<<' ';
        cout<<'\n';
        for(int i:edges)    cout<<i<<' ';
        cout<<'\n';
        int rem = 1;
        sort(nodes.begin(), nodes.end());
        for(;rem <= N && nodes[rem-1] == rem;rem++);
        nodes.clear();
        edges.clear();
        dfs(rem, 0);
        for(int i:nodes)    cout<<i<<' ';
        cout<<'\n';
        for(int i:edges)    cout<<i<<' ';
        return 0;
    }

    find_leaf(1, 0);
    // 빈 줄 출력할거임
    cout<<1<<' '<<N-1<<'\n';
    cout<<leaf<<"\n\n";
    
    dfs(V[leaf][0].first, leaf);
    for(int i:nodes)    cout<<i<<' ';
    cout<<'\n';
    for(int i:edges)    cout<<i<<' ';

}