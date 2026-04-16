#include <bits/stdc++.h>
using namespace std;

int C[100001]{}, down[100001][21]{}, up[100001][21]{}, N, K;
vector<vector<int>> V(100001);
int ans[100001]{};

void dfs(int n, int p){
    ans[n] += down[n][0] = C[n];
    for(int i:V[n]){
        if(i == p)  continue;
        dfs(i,n);
        for(int k=1;k<=K;k++)   down[n][k] += down[i][k-1], ans[n] += down[i][k-1];
    }
}

void dfs2(int n, int p){
    ans[n] += up[n][1] = C[p];
    for(int k=2;k<=K;k++){
        if(n == 1)  continue;
        ans[n] += up[n][k] = down[p][k-1] + up[p][k-1] - down[n][k-2];
    }
    for(int i:V[n]){
        if(i == p)  continue;
        dfs2(i,n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;
    for(int i=1,a,b;i<N;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=1;i<=N;i++)   cin>>C[i];
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=N;i++)   cout<<ans[i]<<'\n';

}