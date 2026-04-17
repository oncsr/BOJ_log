#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    vector<vector<vector<int>>> tree(N+1);
    priority_queue<int, vector<int>, greater<>> PQ;

    int ans = 0;
    for(int i=1;i<=N;i++){
        int A;
        cin>>A;
        tree[i] = vector<vector<int>>(A+1);
        for(int j=1;j<A;j++){
            int a,b;
            cin>>a>>b;
            tree[i][a].push_back(b);
            tree[i][b].push_back(a);
        }
        queue<pair<int, int>> Q;
        Q.push({1,1});
        vector<int> vis(A+1);
        vis[1]++;

        vector<int> leaf;
        while(!Q.empty()){
            int now = Q.front().first;
            int dep = Q.front().second;
            Q.pop();
            int child = 0;
            for(int j:tree[i][now]){
                if(vis[j])  continue;
                child++;
                Q.push({j,dep+1});
                vis[j]++;
            }
            if(!child)  leaf.push_back(dep);
        }

        if(i == 1){
            for(int j:leaf) PQ.push(j), ans = max(ans, j);
            continue;
        }

        int v = PQ.top();
        PQ.pop();
        for(int j:leaf) PQ.push(j+v), ans = max(ans, j+v);


    }
    cout<<ans;

}