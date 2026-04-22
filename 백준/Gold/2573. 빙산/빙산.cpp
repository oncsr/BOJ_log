#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	int n, m;
	cin >> n >> m;
	int arr[300][300]{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int k = 1; k <= 1000; k++) {
		int visit[300][300]{};
		int cnt = 0;
		vector<pair<ii, int>> L;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j])	continue;
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int x = i + dx[d];
					int y = j + dy[d];
					if (x >= 0 && x < n && y >= 0 && y < m)
						cnt += arr[x][y] == 0;
				}
				L.push_back({ {i,j}, max(0,arr[i][j] - cnt) });
			}
		}
		for (pair<ii, int> i : L) {
			arr[i.first.first][i.first.second] = i.second;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j] || visit[i][j])	continue;
				queue<ii> Q;
				Q.push({ i,j });
				visit[i][j]++;
				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					for (int d = 0; d < 4; d++) {
						int xx = x + dx[d];
						int yy = y + dy[d];
						if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visit[xx][yy] && arr[xx][yy]) {
							Q.push({ xx,yy });
							visit[xx][yy]++;
						}
					}
				}
				cnt++;
			}
		}
		if (cnt > 1) {
			cout << k;
			return 0;
		}
	}
	cout << 0;
}