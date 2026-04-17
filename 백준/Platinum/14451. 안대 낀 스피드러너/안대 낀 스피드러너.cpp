#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int N;
char arr[20][20]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// p1, p2의 정보
	int vis[20][20][4][20][20][4]{};

	vis[N - 1][0][0][N - 1][0][3] = 1;
	queue<tuple<int, int, int, int, int, int, int>> Q;
	Q.emplace(N - 1, 0, 0, N - 1, 0, 3, 1);
	while (!Q.empty()) {
		auto [x, y, d, xx, yy, dd, t] = Q.front();
		Q.pop();

		// 전진
		int nx = x, ny = y, nxx = xx, nyy = yy;
		if (d == 0) {
			if (y == N - 1 || arr[x][y + 1] == 'H')	ny = y;
			else	ny = y + 1;
		}
		else if (d == 1) {
			if (x == N - 1 || arr[x + 1][y] == 'H')	nx = x;
			else	nx = x + 1;
		}
		else if (d == 2) {
			if (!y || arr[x][y - 1] == 'H')	ny = y;
			else	ny = y - 1;
		}
		else {
			if (!x || arr[x - 1][y] == 'H')	nx = x;
			else	nx = x - 1;
		}

		if (dd == 0) {
			if (yy == N - 1 || arr[xx][yy + 1] == 'H')	nyy = yy;
			else	nyy = yy + 1;
		}
		else if (dd == 1) {
			if (xx == N - 1 || arr[xx + 1][yy] == 'H')	nxx = xx;
			else	nxx = xx + 1;
		}
		else if (dd == 2) {
			if (!yy || arr[xx][yy - 1] == 'H')	nyy = yy;
			else	nyy = yy - 1;
		}
		else {
			if (!xx || arr[xx - 1][yy] == 'H')	nxx = xx;
			else	nxx = xx - 1;
		}
		if (x == 0 && y == N - 1)	nx = x, ny = y;
		if (xx == 0 && yy == N - 1)	nxx = xx, nyy = yy;

		if ((!vis[nx][ny][d][nxx][nyy][dd] || vis[nx][ny][d][nxx][nyy][dd] > t + 1)) {
			Q.emplace(nx, ny, d, nxx, nyy, dd, t + 1);
			vis[nx][ny][d][nxx][nyy][dd] = t + 1;
		}

		// 좌회전
		int l = (d + 3) % 4, ll = (dd + 3) % 4;
		if (!vis[x][y][l][xx][yy][ll] || vis[x][y][l][xx][yy][ll] > t + 1) {
			Q.emplace(x, y, l, xx, yy, ll, t + 1);
			vis[x][y][l][xx][yy][ll] = t + 1;
		}

		// 우회전
		int r = (d + 1) % 4, rr = (dd + 1) % 4;
		if (!vis[x][y][r][xx][yy][rr] || vis[x][y][r][xx][yy][rr] > t + 1) {
			Q.emplace(x, y, r, xx, yy, rr, t + 1);
			vis[x][y][r][xx][yy][rr] = t + 1;
		}

	}
	int ans = 1e9;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (!vis[0][N - 1][i][0][N - 1][j])	continue;
			ans = min(ans, vis[0][N - 1][i][0][N - 1][j]);
		}
	}
	cout << ans - 1;
}