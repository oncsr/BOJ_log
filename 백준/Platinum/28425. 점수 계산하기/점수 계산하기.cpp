#include <bits/stdc++.h>
using namespace std;

int N, Q;
int sub[100001]{};
vector<vector<int>> V(100001);

// hld
int par[100001]{}, sz[100001]{};
vector<vector<int>> C(100001);
int CN[100001]{}, CI[100001]{}, dep[100001]{};

void init(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		init(i, n);
		sub[n] += sub[i];
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	CN[n] = s, CI[n] = C[s].size(), dep[n] = d;
	C[s].push_back(n);
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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	cin >> sub[i];
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	init(1, 0);
	hld(1, 0, 1, 0);

	for (; Q--;) {
		int r, v;
		cin >> r >> v;
		int g = lca(r, v);
		if (g != v) {
			cout << sub[v] << '\n';
			continue;
		}
		if (r == v) {
			cout << sub[1] << '\n';
			continue;
		}
		int prev = r;
		if (CN[r] == CN[v]) {
			cout << sub[1] - sub[C[CN[v]][CI[v] + 1]] << '\n';
			continue;
		}
		while (CN[r] != CN[v]) {
			prev = CN[r];
			r = par[CN[r]];
		}
		if (r == v)	cout << sub[1] - sub[prev] << '\n';
		else	cout << sub[1] - sub[C[CN[v]][CI[v] + 1]] << '\n';
	}
}