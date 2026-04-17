#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	vector<vector<int>> V(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
	}
	vector<int> D(N + 1, -1);
	queue<pair<int, int>> Q;
	D[X] = 0;
	Q.emplace(X, 0);
	while (!Q.empty()) {
		auto [now, time] = Q.front();
		Q.pop();
		for (int i : V[now]) {
			if (D[i] != -1)	continue;
			D[i] = time + 1;
			Q.emplace(i, time + 1);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (D[i] == K)	cout << i << '\n', cnt++;
	}
	if (!cnt)	cout << -1;

}