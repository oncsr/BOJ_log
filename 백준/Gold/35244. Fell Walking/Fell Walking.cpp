#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> root;
vector<pair<int, int>> infos;
vector<vector<int>> graph;

int find(int x) {
	return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	infos.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> infos[i].first;
		infos[i].second = i;
	}

	graph.resize(N);
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	sort(infos.begin(), infos.end());
	int ans = 1234567;
	for (int i = 0; i < N; i++) {
		root = vector<int>(N);
		iota(root.begin(), root.end(), 0);
		bitset<5000> vis;
		for (int j = i; j < N; j++) {
			auto [h, p] = infos[j];
			for (int q : graph[p]) if (vis[q]) {
				int x = find(p), y = find(q);
				if (x == y) continue;
				root[x] = y;
			}
			if (find(0) == find(1)) {
				ans = min(ans, h - infos[i].first);
				break;
			}
			vis[p] = 1;
		}
	}
	cout << ans;

}