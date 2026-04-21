#include <bits/stdc++.h>
using namespace std;
#define CYCLE 123456789;
vector<vector<int>> V(100001);
int ans, vis[100001]{};

bool dfs(int n){
    bool yes = 1;
    vis[n]++;
    for(int i:V[n]){
        if(vis[i] == 1) {yes = 0; break;}
        if(vis[i] > 1)  continue;
        yes &= dfs(i);
    }
    if(!yes)    ans--;
    else    vis[n]++;
    return yes;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    set<pair<int, int>> multi_check;
    int N, M;
    cin>>N>>M;
    ans = N;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        if(multi_check.count({a,b}))    continue;
        V[a].push_back(b);
    }

    for(int i=1;i<=N;i++){
        if(!vis[i]) dfs(i);
    }
    cout<<ans;
}