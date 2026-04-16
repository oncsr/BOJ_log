#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[5][5]{}, r, c;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < 5; i++)	for (int j = 0; j < 5; j++)	cin >> arr[i][j];
	cin >> r >> c;
	int vis[5][5]{};
	vis[r][c]++;
	queue<tuple<int, int, int>> Q;
	Q.emplace(r, c, 0);
	while (!Q.empty()) {
		auto [x, y, t] = Q.front();
		Q.pop();
		if (arr[x][y] == 1)	return cout << t, 0;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 0 || xx > 4 || yy < 0 || yy > 4 || arr[xx][yy] == -1)	continue;
			if (!vis[xx][yy]) {
				vis[xx][yy]++;
				Q.emplace(xx, yy, t + 1);
			}
			if (arr[xx][yy] == 7)	continue;
			for (int d = 2; d <= 5; d++) {
				xx += dx[k], yy += dy[k];
				if (xx < 0 || xx > 4 || yy < 0 || yy > 4 || arr[xx][yy] == -1) {
					xx -= dx[k], yy -= dy[k];
					if (!vis[xx][yy]) {
						vis[xx][yy]++;
						Q.emplace(xx, yy, t + 1);
					}
					break;
				}
				if (!vis[xx][yy] && arr[xx][yy] == 7) {
					vis[xx][yy]++;
					Q.emplace(xx, yy, t + 1);
					break;
				}
			}
		}
	}
	cout << -1;

}