#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, D;
	cin >> N >> M >> D;

	int L = N / 2 + M / 2;

	int vis[400][400]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<ii, int>> Q;
	if ((N & 1) && (M & 1)) {
		Q.push({ { N / 2, M / 2 }, L });
		vis[N / 2][M / 2]++;
	}
	else if (N & 1) {
		Q.push({ {N / 2, M / 2 - 1}, L });
		Q.push({ {N / 2, M / 2}, L });
		vis[N / 2][M / 2 - 1]++;
		vis[N / 2][M / 2]++;
	}
	else if (M & 1) {
		Q.push({ {N / 2 - 1, M / 2}, L });
		Q.push({ {N / 2, M / 2}, L });
		vis[N / 2 - 1][M / 2]++;
		vis[N / 2][M / 2]++;
	}
	else {
		Q.push({ {N / 2 - 1, M / 2 - 1}, L });
		Q.push({ {N / 2 - 1, M / 2}, L });
		Q.push({ {N / 2, M / 2 - 1}, L });
		Q.push({ {N / 2, M / 2}, L });
		vis[N / 2 - 1][M / 2 - 1]++;
		vis[N / 2 - 1][M / 2]++;
		vis[N / 2][M / 2 - 1]++;
		vis[N / 2][M / 2]++;
	}
	int ans = 0;
	while (!Q.empty()) {
		ii now = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (d == D)	break;
		ans++;
		for (int k = 0; k < 4; k++) {
			int x = now.first + dx[k];
			int y = now.second + dy[k];
			if (x >= 0 && x < N && y >= 0 && y < M && !vis[x][y]) {
				Q.push({ {x,y}, d + 1 });
				vis[x][y]++;
			}
		}
	}
	cout << ans;


}