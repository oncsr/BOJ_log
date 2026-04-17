#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
		// graph[i] = i랑 연결된 친구들을 담을거니까

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	vector<int> visit(N + 1);
	visit[1]++;
	queue<pair<int, int>> Q;
	Q.push({ 1, 0 });

	while (!Q.empty()) {
		auto [now, time] = Q.front();
		Q.pop();

		if (now == N) {
			cout << time;
			return 0;
		}

		for (int next : graph[now]) {
			if (visit[next] != 0)	continue;

			Q.push({ next, time + 1 });
			visit[next]++;

		}

	}

	cout << -1;

}