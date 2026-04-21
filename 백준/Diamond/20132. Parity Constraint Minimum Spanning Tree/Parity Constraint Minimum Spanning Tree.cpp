#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int root[100001]{};
int find(int x){
    if(x == root[x])  return x;
    return root[x] = find(root[x]);
}

int N, M;
vector<vector<pair<int, ll>>> V(100001);
int sz[100001]{}, par[100001]{}, CN[100001]{}, CI[100001]{}, dep[100001]{};
vector<vector<int>> C(100001);
int seg[262145][2]{};
int arr[100001]{};
int ord[100001]{}, rev[100001]{}, cnt = 0;

void dfs(int n, int p){
    sz[n] = 1, par[n] = p;
    for(auto i:V[n]){
        if(i.first == p)    continue;
        dfs(i.first, n);
        sz[n] += sz[i.first];
        arr[i.first] = i.second;
    }
}

void hld(int n, int p, int s, int d){
    dep[n] = d, CN[n] = s, CI[n] = C[s].size();
    C[s].push_back(n);
    int h = -1;
    ord[n] = ++cnt;
    rev[cnt] = n;
    for(auto e:V[n]){
        int i = e.first;
        if(i != p && (h == -1 || sz[i] > sz[h]))    h = i;
    }
    if(h != -1) hld(h, n, s, d);
    for(auto e:V[n]){
        int i = e.first;
        if(i != p && i != h)    hld(i, n, i, d+1);
    }
}

int lca(int a, int b){
    while(CN[a] != CN[b]){
        if(dep[a] > dep[b]) a = par[CN[a]];
        else    b = par[CN[b]];
    }
    return CI[a] > CI[b] ? b : a;
}

void init(int s, int e, int n){
    if(s==e){
        seg[n][arr[rev[s]]&1] = arr[rev[s]];
        return;
    }
    int m=(s+e)>>1;
    init(s,m,n*2);  init(m+1,e,n*2+1);
    for(int i=0;i<2;i++)    seg[n][i] = max(seg[n*2][i], seg[n*2+1][i]);
}

ii query(int s, int e, int l, int r, int n){
    if(l > r || l > e || r < s) return {0,0};
    if(l <= s && e <= r)    return {seg[n][0],seg[n][1]};
    int m=(s+e)>>1;
    ii left = query(s,m,l,r,n*2), right = query(m+1,e,l,r,n*2+1);
    return {max(left.first, right.first), max(left.second, right.second)};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++)   root[i] = i;
    vector<tuple<ll, int, int, int>> E;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        E.push_back({c,a,b,i});
    }
    sort(E.begin(), E.end());
    ll mst = 0, added = 0;
    bool used[300001]{};
    for(auto e:E){
        ll cost = get<0>(e);
        int a = get<1>(e), b = get<2>(e), num = get<3>(e);
        int x = find(a), y = find(b);
        if(x==y)    continue;
        added++;
        used[num]=1;
        root[x] = y;
        mst += cost;
        V[a].push_back({b, cost});
        V[b].push_back({a, cost});
    }
    if(added != N-1){
        cout<<"-1 -1";
        return 0;
    }

    ll ans[2]{};
    ans[0] = 1e18, ans[1] = 1e18;
    ans[mst&1] = mst;

    dfs(1,0);   hld(1,0,1,0);
    init(1,N,1);
    
    for(auto e:E){
        ll cost = get<0>(e);
        int a = get<1>(e), b = get<2>(e), num = get<3>(e);
        if(used[num])   continue;
        int g = lca(a,b);
        ii mx = {0,0}, res;
        while(CN[g] != CN[a]){
            res = query(1,N,ord[CN[a]], ord[a], 1);
            mx.first = max(mx.first, res.first);
            mx.second = max(mx.second, res.second);
            a = par[CN[a]];
        }
        res = query(1,N,ord[g]+1,ord[a],1);
        mx.first = max(mx.first, res.first);
        mx.second = max(mx.second, res.second);
        while(CN[g] != CN[b]){
            res = query(1,N,ord[CN[b]], ord[b], 1);
            mx.first = max(mx.first, res.first);
            mx.second = max(mx.second, res.second);
            b = par[CN[b]];
        }
        res = query(1,N,ord[g]+1,ord[b],1);
        mx.first = max(mx.first, res.first);
        mx.second = max(mx.second, res.second);
        

        ll v;
        if(mx.first){
            v = mst-mx.first+cost;
            ans[v&1] = min(ans[v&1], v);
        }
        if(mx.second){
            v = mst-mx.second+cost;
            ans[v&1] = min(ans[v&1], v);
        }
    }

    cout<<(ans[1] == 1e18?-1:ans[1])<<' '<<(ans[0] == 1e18?-1:ans[0]);


}