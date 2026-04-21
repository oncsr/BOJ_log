#include <bits/stdc++.h>
using namespace std;

int ans[401][401]{};
vector<vector<int>> V(401);
vector<set<int>> can(401);
int vis[401]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, k, deg[401]{};
    cin>>n>>k;
    for(;k--;){
        int a,b;
        cin>>a>>b;
        V[b].push_back(a);
        deg[a]++;
    }
    
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) Q.push(i);
    }

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(int i:V[now]){
            can[i].insert(now);
            for(int j:can[now]) can[i].insert(j);
            if(!(--deg[i]))   Q.push(i);
        }
        
    }

    for(int i=1;i<=n;i++){
        for(int j:can[i]) ans[i][j] = -1, ans[j][i] = 1;
    }

    int s;
    for(cin>>s;s--;){
        int a, b;
        cin>>a>>b;
        cout<<ans[a][b]<<'\n';
    }

}