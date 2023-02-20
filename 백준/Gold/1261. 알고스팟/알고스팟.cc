#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int M, N;
	cin >> M >> N;
	vector<vector<ii> > V(10001);
	int map[100][100]{};
	// 정점 번호 = 행 번호 * M + 열 번호
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			int w = a[j] - '0';
			map[i][j] = w;
			if (i) {
				V[(i - 1) * M + j].push_back({ w,i * M + j });
				int ww = map[i - 1][j];
				V[i * M + j].push_back({ ww,(i - 1) * M + j });
			}

			if (j) {
				V[i * M + j - 1].push_back({ w,i * M + j });
				int ww = map[i][j - 1];
				V[i * M + j].push_back({ ww,i * M + j - 1 });
			}
		}
	}
	priority_queue<ii, vector<ii>, greater<> > PQ;
	vector<int> dist(10001, -1);
	dist[0] = 0;
	PQ.push({ 0,0 });
	while (!PQ.empty()) {
		int d = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();
		if (d > dist[node])	continue;
		for (ii next : V[node]) {
			if (dist[next.second] == -1 || dist[node] + next.first < dist[next.second]) {
				dist[next.second] = dist[node] + next.first;
				PQ.push({ dist[next.second], next.second });
			}
		}
	}
	cout << dist[N * M - 1];
}