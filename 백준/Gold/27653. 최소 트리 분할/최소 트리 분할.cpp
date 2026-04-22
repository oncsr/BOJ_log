#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> v(100001);
ll arr[100001];
ll ans = 0;

void dfs(int n, int p){
    for(int i:v[n]){
        if(i == p) continue;
        ans += max(0LL, arr[i]-arr[n]);
        dfs(i, n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans = arr[1];
    dfs(1,0);
    cout<<ans;
}