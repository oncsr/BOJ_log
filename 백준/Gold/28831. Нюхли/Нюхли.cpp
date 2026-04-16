#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int>> V(100001);
	int deg[100001]{};
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	queue<tuple<int, int, int>> Q;
	int vis[100001]{};
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 1)	Q.emplace(i, 0, 1), vis[i] = 1;
	}

	while (!Q.empty()) {
		auto [n, p, t] = Q.front();
		Q.pop();
		for (int i : V[n]) {
			if (i == p)	continue;
			if (vis[i])	return cout << vis[i] - 1 + t, 0;
			vis[i] = t + 1;
			Q.emplace(i, n, t + 1);
		}
	}

}