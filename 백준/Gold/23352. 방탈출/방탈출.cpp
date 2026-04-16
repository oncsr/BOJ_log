#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	int arr[50][50]{};
	int dx[4] = { 1,0,0,-1 };
	int dy[4] = { 0,1,-1,0 };
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];

	int mxlen = -1, ans = 0;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) {
		if (!arr[i][j])	continue;
		int vis[50][50]{}, a = arr[i][j];
		vis[i][j]++;
		queue<tuple<int, int, int>> Q;
		Q.emplace(i, j, 0);
		while (!Q.empty()) {
			auto [x, y, t] = Q.front();
			Q.pop();
			if (t > mxlen || t == mxlen && a + arr[x][y] > ans)	mxlen = t, ans = a + arr[x][y];
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k], yy = y + dy[k];
				if (xx < 0 || xx >= N || yy < 0 || yy >= M || vis[xx][yy] || !arr[xx][yy])	continue;
				Q.emplace(xx, yy, t + 1);
				vis[xx][yy]++;
			}
		}
	}
	cout << ans;

}