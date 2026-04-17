#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[262145]{};
ll cn[100001]{}, ci[100001]{}, par[100001]{}, sz[100001]{}, dep[100001]{};
ll limit[100001]{}, ord[100001]{}, rev[100001]{}, cnt = 0;
vector<vector<int>> V(100001);
vector<vector<int>> C(100001);
int N, M;
ll lazy[262145]{};

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	C[s].push_back(n);
	ord[n] = ++cnt;
	rev[cnt] = n;
	int h = -1;
	for (int i : V[n]) {
		if (i != p && (h == -1 || sz[i] > sz[h]))	h = i;
	}
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n]) {
		if (i != p && i != h)	hld(i, n, i, d + 1);
	}
}

int lca(int a, int b) {
	while (cn[a] != cn[b]) {
		if (dep[a] > dep[b])	a = par[cn[a]];
		else	b = par[cn[b]];
	}
	return ci[a] < ci[b] ? a : b;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = limit[rev[s]];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] -= lazy[n];
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void upt(int s, int e, int l, int r, ll v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] -= v;
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, v, n * 2);
	upt(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

ll find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return 1e12;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return min(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)	cin >> limit[i];
	dfs(1, 0);	hld(1, 0, 1, 0);
	init(1, N, 1);

	int ans = 0;
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		int g = lca(a, b), temp_a = a, temp_b = b;

		while (cn[g] != cn[a]) {
			upt(1, N, ord[cn[a]], ord[a], c, 1);
			a = par[cn[a]];
		}
		upt(1, N, ord[g], ord[a], c, 1);
		while (cn[g] != cn[b]) {
			upt(1, N, ord[cn[b]], ord[b], c, 1);
			b = par[cn[b]];
		}
		upt(1, N, ord[g] + 1, ord[b], c, 1);
		ll mn = 1e12;
		a = temp_a, b = temp_b;
		while (cn[g] != cn[a]) {
			mn = min(mn, find(1, N, ord[cn[a]], ord[a], 1));
			a = par[cn[a]];
		}
		mn = min(mn, find(1, N, ord[g], ord[a], 1));
		while (cn[g] != cn[b]) {
			mn = min(mn, find(1, N, ord[cn[b]], ord[b], 1));
			b = par[cn[b]];
		}
		mn = min(mn, find(1, N, ord[g], ord[b], 1));
		
		if (mn < 0)	break;
		ans++;

	}
	cout << ans;

}