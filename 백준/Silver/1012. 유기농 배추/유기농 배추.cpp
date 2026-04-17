#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int T;
	for (cin >> T; T--;) {

		int M, N, K;
		cin >> M >> N >> K;

		int graph[50][50]{}, vis[50][50]{};

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
		int ans = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 0)	continue;
				if (vis[i][j] != 0)	continue;
				
				queue<pair<int, int>> Q;
				vis[i][j]++;
				Q.push({ i,j });
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int next_x = x + dx[k];
						int next_y = y + dy[k];
						if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
							if (graph[next_x][next_y] == 0)	continue;
							if (vis[next_x][next_y] != 0)	continue;
							vis[next_x][next_y]++;
							Q.push({ next_x, next_y });
						}
					}
				}
				ans++;

			}
		}

		cout << ans << '\n';
		


	}

}