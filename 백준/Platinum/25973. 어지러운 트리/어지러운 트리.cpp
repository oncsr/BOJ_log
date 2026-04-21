#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 200001

int n, q;
ll dp[N]{}, sz[N]{};
int par[N]{}, dep[N]{}, cn[N]{}, ci[N]{};
vector<vector<int>> V(N), C(N);

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
	dp[n] = sz[n] * sz[n] - 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		dp[n] -= sz[i] * sz[i];
	}
	dp[n] >>= 1;
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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);

	int root = 1;
	for (; q--;) {
		int s, x;
		cin >> s >> x;
		if (s == 1) { root = x; continue; }

		int g = lca(x, root);
		if (g != x) { cout << dp[x] << '\n'; continue; }
		if (x == root) { cout << dp[x] + sz[x] * (n - sz[x]) << '\n'; continue; }
		int prev = root, y = root;
		while (cn[y] != cn[x])	prev = cn[y], y = par[cn[y]];
		if (y == x)	y = prev;
		else	y = C[cn[x]][ci[x] + 1];
		cout << dp[x] + sz[y] * (sz[y] - n) + sz[x] * (n - sz[x]) << '\n';
	}

	

}