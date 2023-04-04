#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int> > V(100001);
int N, M;

int dep[100001]{};
int par[18][100001]{};

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
	int diff = abs(dep[u] - dep[v]);
	// 깊이를 같게 만들기
	if (diff) {
		if (dep[u] < dep[v])	swap(u, v);
		int i = 0;
		while (diff) {
			if (diff % 2)	u = par[i][u];
			i++;
			diff >>= 1;
		}
	}
	if (u == v)	return u;
	// lca 찾기
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
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0, 0);

	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= N; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];

	for (cin >> M; M--;) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

}