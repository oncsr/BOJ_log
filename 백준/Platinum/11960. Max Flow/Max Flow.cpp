#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dep[50001]{}, cn[50001]{}, ci[50001]{}, par[50001]{}, sz[50001]{};
vector<vector<int>> V(50001), C(50001);
int ord[50001]{};
int N, K, cnt = 0;
ll seg[131073]{}, lazy[131073]{};

void prop(int s, int e, int n) {
	if (lazy[n]) {
		ll v = lazy[n];
		seg[n] += v * ((ll)e - s + 1);
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		lazy[n] = 0;
	}
}

void upt(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		seg[n] += ((ll)e - s + 1);
		if (s != e) {
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
		return;
	}
	upt(s, m, l, r, n * 2);
	upt(m + 1, e, l, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	ord[n] = ++cnt;
	C[s].push_back(n);
	int h = -1;
	for (int i : V[n])	if (i != p && (h == -1 || sz[i] > sz[h]))	h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])	if (i != p && i != h)	hld(i, n, i, d + 1);
}

int lca(int a, int b) {
	while (cn[a] != cn[b]) {
		if (dep[a] > dep[b])	a = par[cn[a]];
		else	b = par[cn[b]];
	}
	return ci[a] < ci[b] ? a : b;
}

int cle(int s, int e, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n];
	int m = (s + e) >> 1;
	return max(cle(s, m, n * 2), cle(m + 1, e, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	for (; K--;) {
		int a, b;
		cin >> a >> b;
		int g = lca(a, b);
		
		while (cn[a] != cn[g]) {
			upt(1, N, ord[cn[a]], ord[a], 1);
			a = par[cn[a]];
		}
		upt(1, N, ord[g] + 1, ord[a], 1);
		while (cn[b] != cn[g]) {
			upt(1, N, ord[cn[b]], ord[b], 1);
			b = par[cn[b]];
		}
		upt(1, N, ord[g] + 1, ord[b], 1);
		upt(1, N, ord[g], ord[g], 1);
	}
	cout << cle(1, N, 1);

}