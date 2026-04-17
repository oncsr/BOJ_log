#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<int>> V;
vector<int> arr;
void dfs(int n, int p){
    for(int i:V[n]){
        if(i == p)  continue;
        if(arr[i] != arr[n])    ans++;
        dfs(i,n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    V.resize(N+1);
    arr.resize(N+1);
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    if(arr[1])  ans++;
    dfs(1,0);
    cout<<ans;

}