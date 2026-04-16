#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int N, M, F;
	cin >> N >> M >> F;
	int arr[20][20]{};
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];

	int end_count = 0;
	int pos[20][20]{};
	pair<int, int> to[401]{};

	int tx, ty;
	cin >> tx >> ty;
	tx--, ty--;

	for (int i = 1, a, b, c, d; i <= M; i++) {
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		pos[a][b] = i;
		to[i] = { c,d };
	}

	while (end_count < M) {
		queue<tuple<int, int, int>> Q;
		Q.emplace(tx, ty, 0);
		int vis[20][20]{};
		vis[tx][ty]++;

		int dist = INT_MAX, px = -1, py = -1, p = -1;
		while (!Q.empty()) {
			auto[x, y, t] = Q.front();
			Q.pop();
			if (pos[x][y]) {
				if (dist == INT_MAX) dist = t, px = x, py = y, p = pos[x][y];
				else if (dist == t) {
					if ((x == px && y < py) || (x < px)) px = x, py = y, p = pos[x][y];
				}
			}
			if (t > dist) break;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N || arr[xx][yy] == 1 || vis[xx][yy]) continue;
				Q.emplace(xx, yy, t + 1);
				vis[xx][yy]++;
			}
		}
		if (dist > F) return cout << -1, 0;
		F -= dist;

		Q = queue<tuple<int, int, int>>();
		dist = INT_MAX;
		memset(vis, 0, sizeof(vis));

		Q.emplace(px, py, 0);
		vis[px][py]++;
		bool flag = 0;
		while (!Q.empty()) {
			auto[x, y, t] = Q.front();
			Q.pop();
			if (x == to[p].first && y == to[p].second) {
				if (t > F) return cout << -1, 0;
				F += t;
				end_count++;
				pos[px][py] = 0;
				tx = x, ty = y;
				flag = 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N || arr[xx][yy] == 1 || vis[xx][yy]) continue;
				Q.emplace(xx, yy, t + 1);
				vis[xx][yy]++;
			}
		}
		if (!flag) return cout << -1, 0;
	}
	cout << F;

}