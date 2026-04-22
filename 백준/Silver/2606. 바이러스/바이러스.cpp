#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int computer, M;
	cin >> computer >> M;
	vector<vector<int> > graph(computer + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	queue<int> Q;
	vector<int> visit(computer + 1);

	Q.push(1);
	visit[1]++;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int next : graph[now]) {
			if (visit[next] == 0) {
				cnt++;
				Q.push(next);
				visit[next]++;
			}
		}
	}

	cout << cnt;
}