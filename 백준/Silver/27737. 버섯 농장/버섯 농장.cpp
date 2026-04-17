#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K, S;
	cin >> N >> M >> K;
	S = M;
	int arr[100][100]{}, vis[100][100]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || arr[i][j])	continue;
			int cnt = 0;
			vis[i][j]++;
			queue<pair<int, int>> Q;
			Q.emplace(i, j);
			while (!Q.empty()) {
				auto [x, y] = Q.front();
				Q.pop();
				cnt++;
				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k], yy = y + dy[k];
					if (xx >= 0 && xx < N && yy >= 0 && yy < N && !arr[xx][yy] && !vis[xx][yy]) {
						vis[xx][yy]++;
						Q.emplace(xx, yy);
					}
				}
			}
			M -= (cnt - 1) / K + 1;
		}
	}
	
	if (0 <= M && M < S)	cout << "POSSIBLE\n" << M;
	else	cout << "IMPOSSIBLE";

}