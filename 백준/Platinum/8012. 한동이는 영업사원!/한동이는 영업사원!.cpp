#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int> > V(30001);
int dep[30001]{}, par[16][30001]{}, N, M, a, b;

void dfs(int n, int p, int d) {
	dep[n] = d;
	for (int i : V[n]) {
		if (i != p) {
			par[0][i] = n;
			dfs(i, n, d + 1);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v])	swap(u, v);
	int diff = dep[u] - dep[v];
	int t = 0;
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
	
	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= N; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];

	int temp = -1, s = 0;
	for (cin >> M; M--;) {
		cin >> a;
		if (temp == -1) {
			temp = a;
			continue;
		}
		int g = lca(a, temp);
		s += dep[a] + dep[temp] - 2 * dep[g];
		temp = a;
	}
	cout << s;
}