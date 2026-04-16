#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T, R, C;
	cin >> N >> T >> R >> C;
	R--, C--;
	vector<vector<int>> H(N), V(N);

	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++) {
		char a;
		cin >> a;
		if (a == '#') {
			V[i].push_back(j);
			H[j].push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		sort(V[i].begin(), V[i].end());
		sort(H[i].begin(), H[i].end());
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	vector<vector<vector<int>>> vis(500, vector<vector<int>>(500, vector<int>(2, -1)));
	vis[0][0][0] = 0;
	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> Q;
	Q.emplace(0, 0, 0, 0);
	while (!Q.empty()) {
		auto [t, x, y, s] = Q.top();
		Q.pop();
		if (x == R && y == C)	return cout << t, 0;
		if (t > vis[x][y][s])	continue;
		if (s) {
			int r = upper_bound(V[x].begin(), V[x].end(), y) - V[x].begin();
			if (r != V[x].size()) {
				if (vis[x][V[x][r]][s] == -1 || vis[x][V[x][r]][s] > t + 1) {
					Q.emplace(t + 1, x, V[x][r], s);
					vis[x][V[x][r]][s] = t + 1;
				}
			}
			int l = r - 1;
			if (l >= 0) {
				if (V[x][l] == y)	l--;
				if (l >= 0) {
					if (vis[x][V[x][l]][s] == -1 || vis[x][V[x][l]][s] > t + 1) {
						Q.emplace(t + 1, x, V[x][l], s);
						vis[x][V[x][l]][s] = t + 1;
					}
				}
			}
			int d = upper_bound(H[y].begin(), H[y].end(), x) - H[y].begin();
			if (d != H[y].size()) {
				if (vis[H[y][d]][y][s] == -1 || vis[H[y][d]][y][s] > t + 1) {
					Q.emplace(t + 1, H[y][d], y, s);
					vis[H[y][d]][y][s] = t + 1;
				}
			}
			int u = d - 1;
			if (u >= 0) {
				if (H[y][u] == x)	u--;
				if (u >= 0) {
					if (vis[H[y][u]][y][s] == -1 || vis[H[y][u]][y][s] > t + 1) {
						Q.emplace(t + 1, H[y][u], y, s);
						vis[H[y][u]][y][s] = t + 1;
					}
				}
			}
		}
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
			if (vis[xx][yy][0] == -1 || vis[xx][yy][0] > t + 1) {
				Q.emplace(t + 1, xx, yy, 0);
				vis[xx][yy][0] = t + 1;
			}
		}
		if (!s && (vis[x][y][1] == -1 || vis[x][y][1] > t + T)) {
			Q.emplace(t + T, x, y, 1);
			vis[x][y][1] = t + T;
		}
	}
	


}