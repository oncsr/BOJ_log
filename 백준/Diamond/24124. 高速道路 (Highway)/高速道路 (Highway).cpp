#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int up[262145]{}, down[262145]{};
int arr[262145]{}, ord[262145]{};

int dep[262145]{}, sz[262145]{}, par[262145]{}, cn[262145]{}, ci[262145]{};
int cnt = 0;
vector<vector<int>> C(262145), V(262145);

int dfs(int n, int p){
    sz[n] = 1, par[n] = p;
    for(int i:V[n]){
        if(i == p)  continue;
        sz[n] += dfs(i,n);
    }
    return sz[n];
}

void hld(int n, int p, int s, int d){
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].emplace_back(n);
    ord[n] = ++cnt;
    int h = -1;
    for(int i:V[n]) if(i != p && (h == -1 || sz[i] > sz[h]))    h=i;
    if(h != -1) hld(h, n, s, d);
    for(int i:V[n]) if(i != p && i != h)    hld(i, n, i, d+1);
}

int lca(int a, int b){
    while(cn[a] != cn[b]){
        if(dep[a] > dep[b]) a = par[cn[a]];
        else    b = par[cn[b]];
    }
    return ci[a] < ci[b] ? a : b;
}

void init(int s, int e, int n){
    if(s==e){
        up[n] = down[n] = 1;
        return;
    }
    int m=(s+e)>>1;
    init(s,m,n<<1);  init(m+1,e,(n<<1)+1);
    up[n] = up[n<<1] + up[(n<<1)+1];
    down[n] = down[n<<1] + down[(n<<1)+1];
}

void upt(int s, int e, int i, int o, int l, int r, int n){
    if(s==e){
        if(o > par[o])  up[n] = r, down[n] = l;
        else    up[n] = l, down[n] = r;
        return;
    }
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,o,l,r,n<<1);
    else    upt(m+1,e,i,o,l,r,(n<<1)+1);
    up[n] = up[n<<1] + up[(n<<1)+1];
    down[n] = down[n<<1] + down[(n<<1)+1];
}

int find_up(int s, int e, int l, int r, int n){
    if(l > r || l > e || r < s) return 0;
    if(l <= s && e <= r)    return up[n];
    int m=(s+e)>>1;
    return find_up(s,m,l,r,n<<1) + find_up(m+1,e,l,r,(n<<1)+1);
}

int find_down(int s, int e, int l, int r, int n){
    if(l > r || l > e || r < s) return 0;
    if(l <= s && e <= r)    return down[n];
    int m=(s+e)>>1;
    return find_down(s,m,l,r,n<<1) + find_down(m+1,e,l,r,(n<<1)+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    ii road[100001]{};
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        road[i] = make_pair(a,b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(1,0);   hld(1,0,1,0);
    init(1,N,1);
    for(;M--;){
        char op;
        int a,b,c;
        cin>>op>>a>>b;
        if(op == 'I'){
            cin>>c;
            int x = road[a].first, y = road[a].second;
            if(x == par[y]) swap(x,y);
            upt(1,N,ord[x], x, b, c, 1);
        }
        else{
            int g = lca(a,b);
            int ans = 0;
            while(cn[g] != cn[a]){
                ans += find_up(1,N,ord[cn[a]], ord[a], 1);
                a = par[cn[a]];
            }
            ans += find_up(1,N,ord[g]+1, ord[a], 1);
            while(cn[g] != cn[b]){
                ans += find_down(1,N,ord[cn[b]], ord[b], 1);
                b = par[cn[b]];
            }
            ans += find_down(1,N,ord[g]+1, ord[b], 1);

            cout<<ans<<'\n';
        }
    }
}