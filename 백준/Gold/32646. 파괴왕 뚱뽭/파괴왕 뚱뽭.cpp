#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
 
	int N, M, K, T, q;
	cin >> N >> M >> K >> T >> q;
 
	int arr[100][100]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];
	pair<int, int> tp[100][100];
	for (; K--;) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		tp[a][b] = { c,d };
	}
 
	int D[100][100][101]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	for (int t = 0; t <= T; t++)	D[i][j][t] = -1;
	D[0][0][0] = 0;
	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> Q;
	Q.emplace(0, 0, 0, 0);
	while (!Q.empty()) {
		auto [d, x, y, t] = Q.top();
		Q.pop();
		if (d > D[x][y][t])	continue;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M)	continue;
			if (D[xx][yy][t] == -1 || D[xx][yy][t] > d + arr[xx][yy]) {
				D[xx][yy][t] = d + arr[xx][yy];
				Q.emplace(D[xx][yy][t], xx, yy, t);
			}
		}
		if (t < T) {
			auto& [xx, yy] = tp[x][y];
			if (D[xx][yy][t + 1] == -1 || D[xx][yy][t + 1] > d) {
				D[xx][yy][t + 1] = d;
				Q.emplace(D[xx][yy][t + 1], xx, yy, t + 1);
			}
		}
	}
 
	int mn[100][100]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) {
		mn[i][j] = 2e9;
		for (int t = 0; t <= T; t++) {
			if (D[i][j][t] == -1)	continue;
			mn[i][j] = min(mn[i][j], D[i][j][t]);
		}
	}
 
	for (; q--;) {
		int s, x, y;
		cin >> s >> x >> y;
		x--, y--;
		if (mn[x][y] == 2e9 || mn[x][y] > s)	cout << "0\n";
		else	cout << "1\n";
	}
 
}