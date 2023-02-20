#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, cnt = 0;
	cin >> N;
	while (N) {
		vector<vector<ii> > V(125 * 125);
		int map[125][125]{};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int a;
				cin >> a;
				map[i][j] = a;
				if (i) {
					V[(i - 1) * N + j].push_back({ a,i * N + j });
					int aa = map[i - 1][j];
					V[i * N + j].push_back({ aa,(i - 1) * N + j });
				}
				if (j) {
					V[i * N + j - 1].push_back({ a,i * N + j });
					int aa = map[i][j - 1];
					V[i * N + j].push_back({ aa,i * N + j - 1 });
				}
			}
		}
		
		vector<int> dist(N * N, -1);
		priority_queue<ii, vector<ii>, greater<> > PQ;
		PQ.push({ map[0][0],0 });
		dist[0] = map[0][0];
		while (!PQ.empty()) {
			int d = PQ.top().first;
			int node = PQ.top().second;
			PQ.pop();
			if (d > dist[node])	continue;
			for (ii next : V[node]) {
				if (dist[next.second] == -1 || dist[next.second] > next.first + dist[node]) {
					dist[next.second] = next.first + dist[node];
					PQ.push({ dist[next.second], next.second });
				}
			}
		}
		cout << "Problem " << ++cnt << ": " << dist[N * N - 1] << '\n';
		cin >> N;
	}
}