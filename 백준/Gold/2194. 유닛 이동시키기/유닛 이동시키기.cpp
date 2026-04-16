#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, A, B, K;
	cin >> N >> M >> A >> B >> K;
	int arr[501][501]{}, D[501][501]{};
	for (int a, b; K--; arr[a][b] = 1)	cin >> a >> b;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)	D[i][j] = arr[i][j] + D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
	
	int vis[501][501]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vis[a][b]++;
	queue<tuple<int, int, int>> Q;
	Q.emplace(a, b, 0);
	while (!Q.empty()) {
		auto [x, y, t] = Q.front(); Q.pop();
		if (x == c && y == d)	return cout << t, 0;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx <= 0 || xx + A - 1 > N || yy <= 0 || yy + B - 1 > M || vis[xx][yy])	continue;
			int cnt = D[xx + A - 1][yy + B - 1] - D[xx - 1][yy + B - 1] - D[xx + A - 1][yy - 1] + D[xx - 1][yy - 1];
			if (cnt)	continue;
			Q.emplace(xx, yy, t + 1);
			vis[xx][yy]++;
		}
	}
	cout << -1;

}