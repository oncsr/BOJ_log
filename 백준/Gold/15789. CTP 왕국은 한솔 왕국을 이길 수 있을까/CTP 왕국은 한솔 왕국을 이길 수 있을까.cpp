#include <bits/stdc++.h>
using namespace std;

int vis[100001]{};
int sz = 0, ans = 0;
vector<vector<int>> V(100001);
priority_queue<int> Q;

void dfs(int n){
    sz++, vis[n]++;
    for(int i:V[n]) if(!vis[i])  dfs(i);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    for(;M--;){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int C, H, K;
    cin>>C>>H>>K;
    dfs(C);
    ans = sz;
    sz = 0;
    dfs(H);
    for(int i=1;i<=N;i++){
        sz = 0;
        if(!vis[i]) dfs(i), Q.push(sz);
    }

    while(!Q.empty() && K--){
        ans += Q.top();
        Q.pop();
    }
    cout<<ans;
    
}