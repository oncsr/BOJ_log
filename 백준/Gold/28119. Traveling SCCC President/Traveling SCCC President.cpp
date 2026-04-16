#include <bits/stdc++.h>
using namespace std;

int N, M, S;
vector<tuple<int, int, int>> edges;
int root[2001]{};

int find(int x) {
	return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> S;
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		edges.emplace_back(c, a, b);
	}

	sort(edges.begin(), edges.end());
	iota(root, root + N + 1, 0);

	int ans = 0;
	for (auto [c, a, b] : edges) {
		int x = find(a), y = find(b);
		if (x == y) continue;
		root[x] = y;
		ans += c;
	}

	cout << ans;
}