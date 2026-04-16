#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	char arr[101][101][101]{}, vis[101][101][101]{};
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	queue<tuple<int, int, int, int>> Q;
	Q.emplace(a, b, c, 0);
	vis[a][b][c]++;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)for (int k = 1; k <= N; k++)cin >> arr[j][k][i];

	int dx[6] = { 1,0,0,-1,0,0 };
	int dy[6] = { 0,1,0,0,-1,0 };
	int dz[6] = { 0,0,1,0,0,-1 };

	while (!Q.empty()) {
		auto [x, y, z, t] = Q.front();
		Q.pop();
		if (x == d && y == e && z == f)	return cout << t, 0;
		for (int i = 0; i < 6; i++) {
			x += dx[i], y += dy[i], z += dz[i];
			if (1 <= x && x <= N && 1 <= y && y <= N && 1 <= z && z <= N && arr[x][y][z] == '0' && !vis[x][y][z]) {
				Q.emplace(x, y, z, t + 1);
				vis[x][y][z]++;
			}
			x -= dx[i], y -= dy[i], z -= dz[i];
		}
	}
	cout << -1;

}