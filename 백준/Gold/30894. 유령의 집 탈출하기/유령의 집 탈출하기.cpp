#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	int N, M, sx, sy, ex, ey;
	cin >> N >> M >> sx >> sy >> ex >> ey;
	sx--, sy--, ex--, ey--;
	char A[200][200][4]{};
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> A[i][j][0];
		A[i][j][1] = A[i][j][2] = A[i][j][3] = A[i][j][0];
	}
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			char a = A[i][j][t];
			if (a < '0' || a > '3') continue;
			int dir = (a - '0' + t) % 4;
			int x = i, y = j;
			A[x][y][t] = '#';
			x += dx[dir], y += dy[dir];
			while (0 <= x && x < N && 0 <= y && y < M) {
				if (A[x][y][t] != '.' && A[x][y][t] != 'c') break;
				A[x][y][t] = 'c';
				x += dx[dir], y += dy[dir];
			}
		}
	}

	int vis[200][200][4]{};
	queue<tuple<int, int, int>> Q;
	Q.emplace(sx, sy, 0);
	vis[sx][sy][0]++;
	while (!Q.empty()) {
		auto [x, y, t] = Q.front();
		Q.pop();
		if (x == ex && y == ey) return cout << t, 0;
		if (!vis[x][y][(t + 1) % 4] && A[x][y][(t + 1) % 4] == '.') {
			vis[x][y][(t + 1) % 4]++;
			Q.emplace(x, y, t + 1);
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M || vis[xx][yy][(t + 1) % 4] || A[xx][yy][(t + 1) % 4] != '.') continue;
			vis[xx][yy][(t + 1) % 4]++;
			Q.emplace(xx, yy, t + 1);
		}
	}
	cout << "GG";

}