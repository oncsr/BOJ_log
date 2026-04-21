// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root(2001);

vector<vector<pair<ll, int>>> V(2001);
vector<vector<int>> C(2001);
vector<int> seg(8004);
vector<int> arr(2001);
vector<int> par(2001);
vector<int> sz(2001);
vector<int> CN(2001);
vector<int> CI(2001);
vector<int> dep(2001);
vector<int> ord(2001);
vector<int> rev(2001);
int ch = 0;

int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	for (auto i : V[n]) {
		if (i.second == p)	continue;
		arr[i.second] = i.first;
		dfs(i.second, n);
		sz[n] += sz[i.second];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, CN[n] = s, CI[n] = C[s].size();
	C[s].push_back(n);
	ord[n] = ++ch;
	rev[ch] = n;
	int h = -1;
	for (auto i : V[n]) {
		if (i.second != p && (h == -1 || sz[i.second] > sz[h])) {
			h = i.second;
		}
	}
	if (h != -1)	hld(h, n, s, d);
	for (auto i : V[n])
		if (i.second != h && i.second != p)
			hld(i.second, n, i.second, d + 1);
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (dep[a] > dep[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[rev[s]];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll sol(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(sol(s, m, l, r, n * 2), sol(m + 1, e, l, r, n * 2 + 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    while(cin>>N>>M){
        root = vector<int>(N+1);
        
        V = vector<vector<pair<ll, int>>>(N+1);
        C = vector<vector<int>>(N+1);
        seg = vector<int>(4*N);
        arr = vector<int>(N+1);
        par = vector<int>(N+1);
        sz = vector<int>(N+1);
        CN = vector<int>(N+1);
        CI = vector<int>(N+1);
        dep = vector<int>(N+1);
        ord = vector<int>(N+1);
        rev = vector<int>(N+1);
        ch = 0;
        
        for(int i=1;i<=N;i++)   root[i] = i;
        vector<pair<ll, pair<int, int>>> E;
        for(;M--;){
            int a,b,c;
            cin>>a>>b>>c;
            E.push_back({c,{a,b}});
        }
        sort(E.begin(), E.end());
        ll sum = 0;
        int cnt = 0, pos = -1;
        bool vis[1000001]{};
        for(auto e:E){
            pos++;
            int a = e.second.first, b = e.second.second;
            ll c = e.first;
            int x = find(a), y = find(b);
            if(x==y)    continue;
            
            root[x] = y;
            sum += c;
            cnt++;
            vis[pos] = 1;
            V[a].push_back({c,b});
            V[b].push_back({c,a});
        }
        if(cnt != N-1){
            cout<<"disconnected\n";
            continue;
        }
        dfs(1,0); hld(1,0,1,0);
        init(1,N,1);
        ll ans = 1e18+1;
        pos = -1;
        for(auto e:E){
            pos++;
            int a = e.second.first, b = e.second.second;
            ll c = e.first;
            if(vis[pos]){
                ans = min(ans, sum - 2*c);
                continue;
            }
            
            int g = lca(a, b);
    		ll mx = 0;
    		while (CN[a] != CN[g]) {
    			ll Q = sol(1, N, ord[CN[a]], ord[a], 1);
    			mx = max(mx, Q);
    			a = par[CN[a]];
    		}
    		mx = max(mx, sol(1, N, ord[g] + 1, ord[a], 1));
    		while (CN[b] != CN[g]) {
    			ll Q = sol(1, N, ord[CN[b]], ord[b], 1);
    			mx = max(mx, Q);
    			b = par[CN[b]];
    		}
    		mx = max(mx, sol(1, N, ord[g] + 1, ord[b], 1));
            
            ans = min(ans, sum - mx - c);
        }
        cout<<ans<<'\n';
        
    }
    
    
    return 0;
}