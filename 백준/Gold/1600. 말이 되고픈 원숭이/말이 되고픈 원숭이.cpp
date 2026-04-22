#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int dx1[4] = { 1,0,-1,0 };
	int dy1[4] = { 0,1,0,-1 };
	int dx2[8] = { 1,2,2,1,-1,-2,-2,-1 };
	int dy2[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int k, n, m;
	cin >> k >> m >> n;
	int arr[200][200]{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	queue<pair<ii, ii>> Q;
	int visit[200][200][31]{};
	visit[0][0][k]++;
	Q.push({ {0,0},{0,k} });
	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second.first;
		int re = Q.front().second.second;
		Q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return 0;
		}
		if (re) {
			for (int i = 0; i < 8; i++) {
				int xx = x + dx2[i];
				int yy = y + dy2[i];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visit[xx][yy][re - 1] && arr[xx][yy] != 1) {
					Q.push({ {xx,yy},{cnt + 1,re - 1} });
					visit[xx][yy][re - 1]++;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx1[i];
			int yy = y + dy1[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visit[xx][yy][re] && arr[xx][yy] != 1) {
				Q.push({ {xx,yy},{cnt + 1,re} });
				visit[xx][yy][re]++;
			}
		}
	}
	cout << -1;
}