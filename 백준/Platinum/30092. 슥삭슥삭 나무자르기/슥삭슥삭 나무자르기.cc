#include <bits/stdc++.h>
using namespace std;

int N, Q;
int par[100001]{}, sz[100001]{};
int CN[100001]{}, CI[100001]{}, dep[100001]{};
vector<vector<int>> V(100001);
vector<vector<int>> C(100001);

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, CN[n] = s, CI[n] = C[s].size();
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
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	for (; Q--;) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int g = lca(a, b), ac = lca(a, c), ad = lca(a, d);
		int bc = lca(b, c), bd = lca(b, d);
		if (ac != ad && ((lca(ac, g) == g && ac != g) || (lca(ad, g) == g && ad != g))) {
			cout << "NO\n";
			continue;
		}
		if (bc != bd && ((lca(bc, g) == g && bc != g) || (lca(bd, g) == g && bd != g))) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}

}