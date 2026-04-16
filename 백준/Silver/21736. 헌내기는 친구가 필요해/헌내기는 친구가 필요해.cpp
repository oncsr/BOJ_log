#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	char arr[600][600]{};
	bool vis[600][600]{};
	queue<pair<int, int>> Q;
	int ans = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'I')	Q.emplace(i, j), vis[i][j] = 1;
	}
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!Q.empty()) {
		auto [x, y] = Q.front(); Q.pop();
		if (arr[x][y] == 'P')	ans++;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy] || arr[xx][yy] == 'X')	continue;
			vis[xx][yy] = 1;
			Q.emplace(xx, yy);
		}
	}
	if (ans == 0)	cout << "TT";
	else	cout << ans;

}