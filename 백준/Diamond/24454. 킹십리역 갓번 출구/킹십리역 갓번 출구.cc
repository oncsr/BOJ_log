#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, G;
vector<vector<pair<int, ll>>> V(100001);
vector<vector<int>> C(100001);
int dep[100001]{}, par[100001]{}, sz[100001]{}, cn[100001]{}, ci[100001]{};
int ord[100001]{}, rev[100001]{};
int cnt = 0;
ll seg[262145]{}, lazy[262145]{};

void dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(auto [i,c]:V[n]){
        if(i == p)  continue;
        dfs(i,n);
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    ord[n] = ++cnt;
    rev[cnt] = n;
    int h = -1;
    for(auto [i,c]:V[n])    if(i != p && (h == -1 || sz[i] > sz[h]))    h = i;
    if(h != -1) hld(h,n,s,d);
    for(auto [i,c]:V[n])    if(i != p && i != h)    hld(i,n,i,d+1);
}

void prop(int s, int e, int n){
    if(lazy[n]){
        seg[n] += lazy[n] * ((ll)e-s+1);
        if(s != e){
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void upt(int s, int e, int l, int r, ll v, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s)   return;
    if(l <= s && e <= r){
        seg[n] += v * ((ll)e-s+1);
        if(s != e){
            lazy[n*2] += v;
            lazy[n*2+1] += v;
        }
        return;
    }
    int m=(s+e)>>1;
    upt(s,m,l,r,v,n*2); upt(m+1,e,l,r,v,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll find(int s, int e, int l, int r, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s)   return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>G;
    vector<vector<pair<int, ll>>> graph(N+1);
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }

    vector<ll> D(N+1,-1);
    vector<int> S(N+1);
    vector<int> P(N+1);
    D[G] = 0;
    S[G] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
    Q.emplace(0,G);
    while(!Q.empty()){
        auto [d,n] = Q.top();
        Q.pop();
        if(d > D[n])    continue;
        for(auto [i,c]:graph[n]){
            if(D[i] == -1 || D[i] > d+c){
                D[i] = d+c;
                P[i] = n;
                S[i] = S[n] + 1;
                Q.emplace(D[i],i);
            }
            else if(D[i] == d+c){
                if(S[i] > S[n]+1){
                    D[i] = d+c;
                    P[i] = n;
                    S[i] = S[n] + 1;
                    Q.emplace(D[i],i);
                }
                else if(S[i] == S[n]+1 && n < P[i]){
                    D[i] = d+c;
                    P[i] = n;
                    S[i] = S[n] + 1;
                    Q.emplace(D[i],i);
                }
            }
        }
    }

    vector<int> vis(N+1);
    vis[G]++;
    for(int i=1;i<=N;i++){
        int g = i;
        while(!vis[g]){
            int p = P[g], v = D[g] - D[p];
            V[g].emplace_back(p,v);
            V[p].emplace_back(g,v);
            vis[g]++;
            g = p;
        }
    }
    dfs(G,0);
    hld(G,0,G,0);
    
    ll Vsum = 0;
    int q;
    for(cin>>q;q--;){
        int o, i, v;
        cin>>o>>i;
        if(o == 1)  cin>>v;
        ll res = D[i], len = 0;
        while(cn[G] != cn[i]){
            if(o == 1)  upt(1,N,ord[cn[i]],ord[i],v,1);
            else    res -= find(1,N,ord[cn[i]],ord[i],1);
            len += ci[i] + 1;
            i = par[cn[i]];
        }
        if(o == 1)  upt(1,N,ord[G]+1,ord[i],v,1);
        else    res -= find(1,N,ord[G]+1,ord[i],1);
        len += ci[i];
        res += len * Vsum;
        if(o == 1)  Vsum += v;
        if(o == 2)  cout<<res<<'\n';
    }


}