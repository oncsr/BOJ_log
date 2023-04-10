#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// BFS N회 수행
	for (int i = 1; i <= N; i++) {
		int visit[101]{};
		queue<pair<int, int>> Q;
		visit[i]++;
		Q.push({ i,0 });

		int max_level = 0, cnt = 0;
		while (!Q.empty()) {
			int now = Q.front().first;
			int level = Q.front().second;
			max_level = max(level, max_level);
			Q.pop();
			cnt++;
			for (int next : graph[now]) {
				if (visit[next] == 0) {
					visit[next]++;
					Q.push({ next,level + 1 });
				}
			}
		}

		if (max_level > 6 || cnt != N) {
			cout << "Big World!";
			return 0;
		}
	}
	cout << "Small World!";
}