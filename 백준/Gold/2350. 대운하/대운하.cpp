#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<tuple<int, int, int>> edges;
vector<vector<pair<int, int>>> v(1001);
int root[1001]{}, ans = 0;

int find(int x) { return x == root[x] ? x : root[x] = find(root[x]); }

void dfs(int n, int p, int tar, int mx) {
	if (n == tar) ans = mx;
	for (auto [i, c] : v[n]) if (i != p) dfs(i, n, tar, min(mx, c));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int a, b, c; M--;) {
		cin >> a >> b >> c;
		edges.emplace_back(c, a, b);
	}
	sort(edges.begin(), edges.end(), greater<>());

	iota(root, root + N + 1, 0);
	for (auto [c, a, b] : edges) {
		int x = find(a), y = find(b);
		if (x == y) continue;
		root[x] = y;
		v[a].emplace_back(b, c);
		v[b].emplace_back(a, c);
	}

	for (int a, b; K--;) {
		cin >> a >> b;
		ans = 201;
		dfs(a, 0, b, 201);
		cout << ans << '\n';
	}

}