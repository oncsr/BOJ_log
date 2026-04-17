#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int par[100001]{}, sz[100001]{};
int dep[100001]{}, cn[100001]{}, ci[100001]{};
vector<vector<int>> V(100001), C(100001);

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

int leng(int a, int b) {
	int res = 1, g = lca(a, b);
	while (cn[a] != cn[g]) {
		res += ci[a] + 1;
		a = par[cn[a]];
	}
	res += ci[a] - ci[g];
	while (cn[b] != cn[g]) {
		res += ci[b] + 1;
		b = par[cn[b]];
	}
	res += ci[b] - ci[g];
	return res;
}

ll sol(ll n) { return n * (n + 1) / 2; }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	dfs(1, 0);	hld(1, 0, 1, 0);

	for (; Q--;) {
		int a, b, c;
		cin >> a >> b >> c;
		
		ll A = leng(a, b), B = leng(b, c), C;
		int g1 = lca(a, b), g2 = lca(b, c), g3 = lca(a, c);

		if (g1 == g2)	C = leng(b, g3);
		else if (g1 == g3)	C = leng(b, g2);
		else	C = leng(b, g1);

		cout << sol(C - 1) + sol(A + B - 1 - C) << '\n';

	}

}