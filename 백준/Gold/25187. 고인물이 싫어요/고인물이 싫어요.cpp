#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int vis[100001]{}, arr[100001]{};
int ans[100001]{};
vector<vector<int>> V(100001);

vector<int> chk;

pair<int, int> dfs(int n){
    pair<int, int> res = {arr[n] == 0, arr[n] == 1};
    chk.push_back(n);
    vis[n]++;
    for(int i:V[n]){
        if(vis[i])  continue;
        pair<int, int> child = dfs(i);
        res.first += child.first;
        res.second += child.second;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m>>q;

    for(int i=1;i<=n;i++)   cin>>arr[i];
    for(;m--;){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])  continue;
        chk = vector<int>();

        pair<int, int> res = dfs(i);
        bool c = res.second > res.first;
        for(int i:chk)  ans[i] = c;

    }

    for(;q--;){
        int a;
        cin>>a;
        cout<<ans[a]<<'\n';
    }
    
    

}