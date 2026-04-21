#include <bits/stdc++.h>
using namespace std;

int root[101]{};
int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int E[101][101]{}, N, M;
    cin>>N>>M;
    vector<vector<int>> dist(101, vector<int>(101, 1e9));
    for(int i=1;i<=N;i++)   root[i] = i, dist[i][i] = 0;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        E[a][b] = E[b][a] = 1;
        dist[a][b] = dist[b][a] = 1;
        int x = find(a), y = find(b);
        root[x] = y;
    }

    for(int i=1;i<=N;i++){  
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }

    vector<vector<int>> T(101);
    for(int i=1;i<=N;i++){
        T[find(i)].push_back(i);
    }

    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(T[i].empty())    continue;
        int mn = 1e9, leader = -1;
        for(int j:T[i]){
            int mx = 0;
            for(int k:T[i]) mx = max(mx, dist[j][k]);
            if(mx < mn) mn = mx, leader = j;
        }
        ans.push_back(leader);
    }
    sort(ans.begin(), ans.end());

    cout<<ans.size()<<'\n';
    for(int i:ans)  cout<<i<<'\n';


        

}