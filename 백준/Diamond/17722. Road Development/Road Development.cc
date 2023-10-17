#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
int root[100001]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int seg[262145]{}, lazy[262145]{};
vector<vector<int>> V(100001);
int sz[100001]{}, par[100001]{}, dep[100001]{}, CN[100001]{}, CI[100001]{};
vector<vector<int>> C(100001);
int ord[100001]{}, cnt = 0;
vector<int> vis(100001);

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	vis[n]++;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, CN[n] = s, CI[n] = C[s].size();
	C[s].push_back(n);
	vis[n]++;
	ord[n] = ++cnt;
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			hld(i, n, i, d + 1);
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (dep[a] > dep[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] = 0;
		if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = 1;
		lazy[n] = 0;
		return;
	}
}
void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = 1;
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void upt(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] = 0;
		if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = 1;
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, n * 2);	upt(m + 1, e, l, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int sum(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return sum(s, m, l, r, n * 2) + sum(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	root[i] = i;

	vector<tuple<int, int, int>> Query;
	for (int i = 0; i < Q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		Query.push_back({ t,a,b });
		if (t == 1) {
			int x = find(a), y = find(b);
			if (x == y)	continue;
			root[x] = y;
			V[a].push_back(b);
			V[b].push_back(a);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[i])	dfs(i, 0);
	}
	vis = vector<int>(100001);
	for (int i = 1; i <= N; i++) {
		if (!vis[i])	hld(i, 0, i, 0);
	}
	init(1, N, 1);
	for (int i = 1; i <= N; i++)	root[i] = i;
	for (auto q : Query) {
		int t = get<0>(q), a = get<1>(q), b = get<2>(q);
		if (t == 1) {
			int x = find(a), y = find(b);
			if (x == y) {
				// upt
				int g = lca(a, b);
				while (CN[g] != CN[a]) {
					upt(1, N, ord[CN[a]], ord[a], 1);
					a = par[CN[a]];
				}
				upt(1, N, ord[g] + 1, ord[a], 1);
				while (CN[g] != CN[b]) {
					upt(1, N, ord[CN[b]], ord[b], 1);
					b = par[CN[b]];
				}
				upt(1, N, ord[g] + 1, ord[b], 1);
			}
			else	root[x] = y;
		}
		else {
			int x = find(a), y = find(b);
			int ans = 0;
			if (x == y) {
				int g = lca(a, b);
				while (CN[g] != CN[a]) {
					ans += sum(1, N, ord[CN[a]], ord[a], 1);
					a = par[CN[a]];
				}
				ans += sum(1, N, ord[g] + 1, ord[a], 1);

				while (CN[g] != CN[b]) {
					ans += sum(1, N, ord[CN[b]], ord[b], 1);
					b = par[CN[b]];
				}
				ans += sum(1, N, ord[g] + 1, ord[b], 1);
			}
			else	ans = -1;
			cout << ans << '\n';
		}
	}


}