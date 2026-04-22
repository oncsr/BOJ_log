#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> V(100000);
ll arr[100000]{};

ll dfs(int n, int p){
    ll s = arr[n];
    for(int i:V[n]){
        if(i == p)    continue;
        s += max(0LL, dfs(i,n));
    }
    return s;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<dfs(0,-1);
}