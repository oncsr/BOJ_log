#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    vector<vector<int>> V(100);
    vector<pair<int, int>> arr;
    for(int i=0;i<N;i++){
        int o, a, b;
        cin>>o>>a>>b;
        if(o == 1){
            for(int j=0;j<arr.size();j++){
                auto [p,q] = arr[j];
                if((p < a && a < q) || (p < b && b < q))    V[arr.size()].push_back(j);
                if((a < p && p < b) || (a < q && q < b))    V[j].push_back(arr.size());
            }
            arr.emplace_back(a,b);
        }
        else{
            a--,b--;
            int poss = 0;
            int vis[100]{};
            queue<int> Q;
            vis[a]++;
            Q.push(a);
            while(!Q.empty()){
                int now = Q.front();
                Q.pop();
                if(now == b){poss = 1;break;}
                for(int j:V[now]){
                    if(vis[j])  continue;
                    vis[j]++;
                    Q.push(j);
                }
            }
            cout<<poss<<'\n';
        }
    }
    
}