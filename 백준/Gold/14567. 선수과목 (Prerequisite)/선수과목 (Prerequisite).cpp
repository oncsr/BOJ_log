#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m;
	vector<vector<int>> V(1001);
	int deg[1001]{};
	for (cin >> n >> m; m--;) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		deg[b]++;
	}
	int ans[1001]{};
	queue<pair<int, int>> Q;
	for (int i = 1; i <= n; i++) {
		if (!deg[i])	ans[i] = 1, Q.emplace(i, 1);
	}

	while (!Q.empty()) {
		auto [now, t] = Q.front();
		Q.pop();
		for (int i : V[now]) {
			if (!(--deg[i]))	ans[i] = t + 1, Q.emplace(i, t + 1);
		}
	}
	for (int i = 1; i <= n; i++)	cout << ans[i] << ' ';
	
	
}