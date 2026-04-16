#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<tuple<int,int,int>> Edges;
vector<tuple<int,int,int,int>> Queries;

int r[200001]{};
vector<vector<pair<int,int>>> V(200001);
int par[200001]{}, sz[200001]{}, dep[200001]{}, cn[200001]{}, ci[200001]{}, ord[200001]{}, rev[200001]{}, A[200001]{}, seg[524288]{};
int cnt = 0;

int f(int x){return x==r[x]?x:r[x]=f(r[x]);}

void dfs(int n, int p){
    par[n] = p, sz[n] = 1;
    for(auto [i,c]:V[n]) if(i != p) {
        dfs(i,n);
        sz[n] += sz[i];
        A[i] = c;
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = n==s ? 0 : ci[p]+1;
    ord[n] = ++cnt;
    rev[cnt] = n;
    int h = -1;
    for(auto [i,c]:V[n]) if(i != p && (h == -1 || sz[i] > sz[h])) h = i;
    if(h != -1) hld(h,n,s,d);
    for(auto [i,c]:V[n]) if(i != p && i != h) hld(i,n,i,d+1);
}

int init(int s, int e, int n){
    if(s == e) return seg[n] = A[rev[s]];
    int m=(s+e)>>1;
    return seg[n] = max(init(s,m,n*2), init(m+1,e,n*2+1));
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s) return 0;
    if(l<=s && e<=r) return seg[n];
    int m=(s+e)>>1;
    return max(find(s,m,l,r,n*2),find(m+1,e,l,r,n*2+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>Q;
    Edges = vector<tuple<int,int,int>>(M);
    for(auto &[c,a,b]:Edges) cin>>a>>b>>c;
    Queries = vector<tuple<int,int,int,int>>(Q);
    int temp1 = 0;
    for(auto &[a,b,c,d]:Queries) cin>>a>>b, c = temp1++;
    
    iota(r, r+N+1, 0);
    
    sort(Edges.begin(), Edges.end());
    for(auto [c,a,b]:Edges){
        int x = f(a), y = f(b);
        if(x == y) continue;
        r[x] = y;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }
    
    dfs(1,0);
    hld(1,0,1,0);
    init(1,N,1);
    
    for(auto &[_a,_b,i,v]:Queries){
        int a = _a, b = _b;
        int res = 0;
        while(cn[a] != cn[b]){
            if(dep[a] > dep[b]) swap(a,b);
            res = max(res, find(1,N,ord[cn[b]],ord[b],1));
            b = par[cn[b]];
        }
        if(ci[a] < ci[b]) swap(a,b);
        res = max(res, find(1,N,ord[b]+1,ord[a],1));
        v = res;
    }
    
    sort(Queries.begin(), Queries.end(), [](auto a, auto b) -> bool {
        return get<3>(a) < get<3>(b);
    });
    
    int C[200001]{};
    fill(C+1, C+N+1, 1);
    iota(r, r+N+1, 0);
    
    vector<pair<int,int>> ans(Q);
    int idx = 0;
    for(auto [a,b,i,v]:Queries){
        while(idx<M && get<0>(Edges[idx])<=v){
            int x = f(get<1>(Edges[idx]));
            int y = f(get<2>(Edges[idx]));
            idx++;
            if(x == y) continue;
            C[y] += C[x];
            r[x] = y;
        }
        ans[i].first = v;
        ans[i].second = C[f(a)];
    }
    
    for(auto [a,b] : ans) cout<<a<<' '<<b<<'\n';
    
}