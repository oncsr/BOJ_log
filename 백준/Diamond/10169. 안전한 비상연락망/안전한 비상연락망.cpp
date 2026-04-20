#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int root[100001]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

vector<vector<ii>> V(100001);
vector<vector<int>> C(100001);
int par[100001]{}, sz[100001]{}, dep[100001]{}, cn[100001]{}, ci[100001]{};
int ord[100001]{}, cnt = 0;
vector<int> seg(262145, 1e9);
vector<int> lazy(262145, 1e9);

void dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (auto [i, c] : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

int arr[100001]{};

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	C[s].push_back(n);
	ord[n] = ++cnt;
	int h = -1;
	for (auto [i, c] : V[n])	if (i != p && (h == -1 || sz[i] > sz[h]))	h = i;
	if (h != -1)	hld(h, n, s, d);
	for (auto [i, c] : V[n])	if (i != p && i != h)	hld(i, n, i, d + 1);
}

int lca(int a, int b) {
	while (cn[a] != cn[b]) {
		if (dep[a] > dep[b])	a = par[cn[a]];
		else	b = par[cn[b]];
	}
	return ci[a] < ci[b] ? a : b;
}

void prop(int s, int e, int n) {
	if (lazy[n] != 1e9) {
		seg[n] = min(seg[n], lazy[n]);
		if (s != e) {
			lazy[n * 2] = min(lazy[n * 2], lazy[n]);
			lazy[n * 2 + 1] = min(lazy[n * 2 + 1], lazy[n]);
		}
		lazy[n] = 1e9;
	}
}

void upt(int s, int e, int l, int r, int v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] = min(seg[n], v);
		if (s != e) {
			lazy[n * 2] = min(lazy[n * 2], v);
			lazy[n * 2 + 1] = min(lazy[n * 2 + 1], v);
		}
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, v, n * 2);	upt(m + 1, e, l, r, v, n * 2 + 1);
}

ll findmin(int s, int e, int i, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n];
	int m = (s + e) >> 1;
	if (i <= m)	return findmin(s, m, i, n * 2);
	return findmin(m + 1, e, i, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	root[i] = i;
	vector<tuple<ll, int, int, int>> E;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.push_back({ c,a,b,i });
	}
	sort(E.begin(), E.end());
	int use[300001]{};
	ll S = 0;
	for (auto [c, a, b, n] : E) {
		int x = find(a), y = find(b);
		if (x == y)	continue;
		S += c;
		root[x] = y;
		use[n]++;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	dfs(1, 0);	hld(1, 0, 1, 0);

	for (auto [c, a, b, n] : E) {
		if (use[n])	continue;

		int g = lca(a, b);
		while (cn[g] != cn[a]) {
			upt(1, N, ord[cn[a]], ord[a], c, 1);
			a = par[cn[a]];
		}
		upt(1, N, ord[g] + 1, ord[a], c, 1);
		while (cn[g] != cn[b]) {
			upt(1, N, ord[cn[b]], ord[b], c, 1);
			b = par[cn[b]];
		}
		upt(1, N, ord[g] + 1, ord[b], c, 1);
	}
	vector<ll> ans(M);
	for (auto [c, a, b, n] : E) {
		if (!use[n]) { ans[n] = S; continue; }
		ll g;
		if (par[a] == b)	g = findmin(1, N, ord[a], 1);
		else	g = findmin(1, N, ord[b], 1);
		if (g == 1e9)	ans[n] = -1;
		else	ans[n] = S - c + g;
	}

	for (ll i : ans)	cout << i << '\n';



}