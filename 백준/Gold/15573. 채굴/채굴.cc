#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	int arr[1000][1000]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];


	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	int vis[1000][1000]{};
	for (int i = 0; i < N; i++) {
		vis[i][0]++;
		Q.push({ arr[i][0], i, 0 });
		if (!vis[i][M - 1]) {
			vis[i][M - 1]++;
			Q.push({ arr[i][M - 1], i, M - 1 });
		}
	}
	for (int j = 1; j < M - 1; j++) {
		vis[0][j]++;
		Q.push({ arr[0][j], 0, j });
	}
	int cnt = 0, ans = 0;
	while (!Q.empty()) {
		auto [v, x, y] = Q.top();
		cnt++;
		Q.pop();
		ans = max(ans, v);
		if (cnt == K)	break;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < N && yy >= 0 && yy < M && !vis[xx][yy]) {
				vis[xx][yy]++;
				Q.push({ arr[xx][yy], xx, yy });
			}
		}

	}
	cout << ans;

}