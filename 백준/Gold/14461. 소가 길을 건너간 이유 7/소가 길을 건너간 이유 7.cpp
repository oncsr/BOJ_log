#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T;
	cin >> N >> T;
	int arr[101][101]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j];

	int vis[101][101][3]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> Q;

	vis[1][1][0]++;
	Q.emplace(0, 1, 1, 0);
	while (!Q.empty()) {
		auto [time, x, y, t] = Q.top();
		Q.pop();
		if (x == N && y == N) {
			cout << time;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 1 && xx <= N && yy >= 1 && yy <= N && !vis[xx][yy][(t + 1) % 3]) {
				vis[xx][yy][(t + 1) % 3]++;
				int next_time = time + T;
				if ((t + 1) % 3 == 0)	next_time += arr[xx][yy];
				Q.emplace(next_time, xx, yy, (t + 1) % 3);
			}
		}
	}



}