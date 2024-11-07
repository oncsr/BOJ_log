#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

vector<vector<int>> C(40001);
vector<vector<pair<int, int>>> V(40001);
int par[40001]{}, sz[40001]{}, dep[40001]{}, cn[40001]{}, ci[40001]{};
int S[40001]{};

int dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (auto [i, c] : V[n])	if (i != p)	sz[n] += dfs(i, n);
	return sz[n];
}

void hld(int n, int p, int s, int d, int t) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	S[n] = t;
	if (!C[s].empty())	S[n] += S[C[s].back()];
	C[s].push_back(n);
	
	int h = -1, g = -1;
	for (auto [i, c] : V[n])	if (i != p && (h == -1 || sz[i] > sz[h]))	h = i, g = c;
	if (h != -1)	hld(h, n, s, d, g);
	for (auto [i, c] : V[n])	if (i != p && i != h)	hld(i, n, i, d + 1, c);
}

int sol(int a, int b) {
	int res = 0;
	while (cn[a] != cn[b]) {
		if (dep[a] < dep[b])	swap(a, b);
		res += S[a];
		a = par[cn[a]];
	}
	return res + (ci[a] < ci[b] ? S[b] - S[a] : S[a] - S[b]);
}

int main() {

	int N, M;
	cin >> N;
	for (int i = 1, a, b, c; i < N; i++) {
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}
	dfs(1, 0);
	hld(1, 0, 1, 0, 0);
	for (cin >> M; M--;) {
		int a, b;
		cin >> a >> b;
		cout << sol(a, b) << '\n';
	}

}