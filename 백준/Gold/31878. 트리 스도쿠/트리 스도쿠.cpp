#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int N;
    cin>>N;
 
    vector<pair<int, int>> arr(N);
    int c = 1;
    for(auto &[a,b] : arr)  cin>>a, b = c++;
    sort(arr.begin(), arr.end());
 
    vector<vector<int>> V(N+1);
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);  V[b].push_back(a);
    }
 
    queue<int> Q;
    vector<int> vis(N+1), ans(N+1);
    Q.push(1);
    vis[1]++;
    int g = 0;
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        ans[n] = arr[g++].second;
        for(int i:V[n]){
            if(vis[i])  continue;
            Q.push(i);
            vis[i]++;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=N;i++)   cout<<ans[i]<<' ';
 
 
}
