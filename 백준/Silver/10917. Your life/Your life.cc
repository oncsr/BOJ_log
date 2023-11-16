#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int vis[200001]{};
	queue<pair<int, int>> Q;
	Q.push({ 1,0 });
	vis[1]++;
	
	while (!Q.empty()) {
		auto [x, t] = Q.front();
		Q.pop();
		if (x == n) {
			cout << t;
			return 0;
		}
		for (int next : graph[x]) {
			if (vis[next])	continue;
			Q.push({ next, t + 1 });
			vis[next]++;
		}
	}

	cout << -1;

}