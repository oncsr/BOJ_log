#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	char arr[20][20]{};
	int towns = 0, ans = 1e9;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j], towns += arr[i][j] == '1';

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	for (int a = 0; a < N; a++)	for (int b = 0; b < M; b++) {
		if (arr[a][b] == '1')	continue;
		for (int c = a; c < N; c++)	for (int d = b; d < M; d++) {
			if (arr[c][d] == '1')	continue;
			if (a == c && b == d)	continue;
			bitset<400> vis;
			vis[a * M + b] = 1;
			vis[c * M + d] = 1;
			queue<tuple<int, int, int>> Q;
			int cnt = 0;
			Q.emplace(a, b, 0);
			Q.emplace(c, d, 0);
			while (!Q.empty()) {
				auto [x, y, t] = Q.front();
				Q.pop();
				if (arr[x][y] == '1')	cnt++;
				if (cnt == towns) { ans = min(ans, t); break; }
				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k], yy = y + dy[k];
					if (xx >= 0 && xx < N && yy >= 0 && yy < M && !vis[xx * M + yy]) {
						Q.emplace(xx, yy, t + 1);
						vis[xx * M + yy] = 1;
					}
				}
			}
		}
	}
	cout << ans;

}