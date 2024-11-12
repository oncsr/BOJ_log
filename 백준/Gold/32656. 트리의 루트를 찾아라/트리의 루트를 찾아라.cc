#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    
    vector<vector<int>> V(200001);
    for(int i=1,a,b;i<N;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    int A, B, X;
    cin>>A>>B>>X;
    if(A == B)  return cout<<N,0;
    int par[200001]{};
    int d[200001]{};
    
    function<void(int, int, int)> dfs = [&](int n, int p, int D) -> void {
        par[n] = p;
        if(n == D){
            if(n == X)  return;
            while(par[n] != X)  n = par[n];
            d[n] = 1;
            return;
        }
        
        for(int i:V[n]){
            if(i == p)  continue;
            dfs(i,n,D);
        }
    };
    dfs(X,0,A);
    dfs(X,0,B);
    int ans = 0;
    function<void(int, int)> sol = [&](int n, int p) -> void{
        if(d[n])    return;
        ans++;
        for(int i:V[n]){
            if(i == p)  continue;
            sol(i,n);
        }
    };
    sol(X,0);
    cout<<ans;
    
}