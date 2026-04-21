#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V;
vector<int> sz, par, dep, cn, ci;
vector<vector<int>> C;

void dfs(int n, int p){
    sz[n] = 1, par[n] = p;
    for(int i:V[n]){
        if(i == p)  continue;
        dfs(i, n);
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    int h=-1;
    for(int i:V[n]) if(i!=p && (h==-1 || sz[i] > sz[h]))    h = i;
    if(h != -1) hld(h, n, s, d);
    for(int i:V[n]) if(i!=p && i!=h)    hld(i, n, i, d+1);
}

int lca(int a, int b){
    while(cn[a] != cn[b]){
        if(dep[a] > dep[b]) a = par[cn[a]];
        else    b = par[cn[b]];
    }
    return ci[a] < ci[b] ? a : b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T, tc = 1;
    for(cin>>T;T--;){
        int n, q, r;
        cin>>n>>q>>r;

        V = vector<vector<int>>(n+1);
        C = vector<vector<int>>(n+1);
        sz = vector<int>(n+1);
        par = vector<int>(n+1);
        dep = vector<int>(n+1);
        cn = vector<int>(n+1);
        ci = vector<int>(n+1);

        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }

        dfs(r,0);   hld(r,0,r,0);
        int root = r;

        cout<<"Case #"<<tc++<<":\n";
        for(;q--;){
            int s,u;
            cin>>s>>u;
            if(!s)  {root=u;continue;}
            int g = lca(u,root);
            
            if(g != u)  {cout<<sz[u]<<'\n';continue;}
            if(u == root)   {cout<<n<<'\n';continue;}
            int a = root, prev = a;
            while(cn[a] != cn[u])   prev = cn[a], a = par[cn[a]];
            if(a == u)  cout<<n-sz[prev]<<'\n';
            else    cout<<n-sz[C[cn[u]][ci[u]+1]]<<'\n';


        }

    }
}