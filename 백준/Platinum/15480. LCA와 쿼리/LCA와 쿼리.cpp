#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > V(100001);
int dep[100001]{}, par[18][100001]{};
int N, M, a, b, c;

void dfs(int n, int p, int d) {
	dep[n] = d;
	for (int i : V[n]) {
		if (i == p)	continue;
		par[0][i] = n;
		dfs(i, n, d + 1);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v])	swap(u, v);
	int diff = dep[u] - dep[v], t = 0;
	while (diff) {
		if (diff % 2)	u = par[t][u];
		t++;
		diff >>= 1;
	}
	if (u == v)	return u;
	for (int i = log2(dep[u]); i >= 0; i--) {
		if (par[i][u] == par[i][v])	continue;
		u = par[i][u], v = par[i][v];
	}
	return par[0][u];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0, 0);
	// par[i][j] = j번의 2^i번째 조상 (없으면 0)
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= N; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	for (cin >> M; M--;) {
		cin >> a >> b >> c;
		int g1 = lca(a, b), g2 = lca(a, c), g3 = lca(b, c);
		if (dep[g1] > dep[g2])	cout << (dep[g1] > dep[g3] ? g1 : g3);
		else	cout << (dep[g2] > dep[g3] ? g2 : g3);
		cout << '\n';
	}
}