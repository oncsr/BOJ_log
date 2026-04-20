#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int root[200001]{}, cycle[200001]{},C, E;
int num[200001]{}, g = 1;
vector<vector<int>> V(200001);

int find(int x){
    if(x==root[x])  return x;
    return root[x] = find(root[x]);
}

bool find_cycle(int n, int p){
    if(n == E)  return cycle[n] = 1;
    for(int i:V[n]){
        if(i == p)  continue;
        if(find_cycle(i,n)) return cycle[n] = 1;
    }
    return 0;
}

void dfs(int n, int p, int k){
    num[n] = k;
    int t = 0;
    for(int i:V[n]){
        if(i == p)  continue;
        if(cycle[n]){
            if(cycle[i])    dfs(i, n, i);
            else    dfs(i, n, n);
        }
        else    dfs(i, n, k);
    }
}



int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)   root[i] = i;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int x = find(a), y = find(b);
        if(x == y){
            C = a, E = b;
            continue;
        }
        V[a].push_back(b);
        V[b].push_back(a);
        root[x] = y;
    }
    find_cycle(C, 0);
    dfs(C, 0, C);

    for(;q--;){
        int a,b;
        cin>>a>>b;
        cout<<(num[a] == num[b]?1:2)<<'\n';
    }

}