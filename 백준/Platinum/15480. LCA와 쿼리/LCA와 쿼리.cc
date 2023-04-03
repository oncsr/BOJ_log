#include <iostream>
#include <vector>
using namespace std;

int N, M;

int par[100001]{}, sz[100001]{}, real_dep[100001]{};
int CN[100001]{}, CI[100001]{}, dep[100001]{};
vector<vector<int> > C(100001);

vector<vector<int> > T(100001);

void dfs(int n, int p, int d) {
	par[n] = p, sz[n] = 1;
	real_dep[n] = d;
	for (int i : T[n]) {
		if (i != p) {
			dfs(i, n, d + 1);
			sz[n] += sz[i];
		}
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d;
	CN[n] = s;
	CI[n] = C[s].size();
	C[s].push_back(n);

	int h = -1;
	for (int i : T[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : T[n])
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	dfs(1, 0, 0), hld(1, 0, 1, 0);
	for (cin >> M; M--;) {
		int r, u, v;
		cin >> r >> u >> v;
		int g1 = lca(r, u), g2 = lca(r, v), g3 = lca(u, v);
		
		if (real_dep[g1] > real_dep[g2]) {
			if (real_dep[g1] > real_dep[g3]) {
				cout << g1 << '\n';
			}
			else {
				cout << g3 << '\n';
			}
		}
		else {
			if (real_dep[g2] > real_dep[g3]) {
				cout << g2 << '\n';
			}
			else {
				cout << g3 << '\n';
			}
		}
	}
}