#include <iostream>
#include <queue>
#include <set>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, map[1000][1000]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	cin >> map[i][j];

	int island[500010]{}, id = 2;
	int visit[1000][1000]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] || !map[i][j])	continue;
			visit[i][j]++;
			map[i][j] = id;
			int cnt = 1;
			queue<ii> Q;
			Q.push({ i,j });
			while (!Q.empty()) {
				ii now = Q.front();
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int x = now.first + dir[k][0];
					int y = now.second + dir[k][1];
					if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && map[x][y]) {
						visit[x][y]++;
						map[x][y] = id;
						cnt++;
						Q.push({ x,y });
					}
				}
			}
			island[id++] = cnt;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j])	continue;
			
			set<int> S;
			if (i) {
				if (map[i - 1][j])
					S.insert(map[i - 1][j]);
			}
			if (i != n - 1) {
				if (map[i + 1][j])
					S.insert(map[i + 1][j]);
			}
			if (j) {
				if (map[i][j - 1])
					S.insert(map[i][j - 1]);
			}
			if (j != m - 1) {
				if (map[i][j + 1])
					S.insert(map[i][j + 1]);
			}
			int s = 0;
			for (int k : S) {
				s += island[k];
			}
			ans = max(ans, s + 1);
		}
	}
	cout << ans;
}