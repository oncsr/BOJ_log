#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> V(101);
vector<int> vis(101);
vector<int> P(101);
vector<int> sel;

void dfs(int n, int p, int k){
    P[n] = p;
    if(vis[n] == k){
        int g = n;
        do{
            sel.push_back(n);
            n = P[n];
        }while(g != n);
        return;
    }
    else if(vis[n]) return;
    vis[n] = k;
    dfs(V[n], n, k);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++)   cin>>V[i];

    int c = 0;
    for(int i=1;i<=N;i++){
        if(vis[i])  continue;
        dfs(i, 0, ++c);
    }
    sort(sel.begin(), sel.end());
    cout<<sel.size()<<'\n';
    for(int i:sel)  cout<<i<<'\n';

}