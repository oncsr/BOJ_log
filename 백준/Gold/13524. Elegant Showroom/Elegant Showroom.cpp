#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	char arr[401][401]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++)	cin >> arr[i][j];

	int r, c;
	cin >> r >> c;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	Q.emplace(1, r, c);
	vector<vector<int>> D(401, vector<int>(401, -1));
	D[r][c] = 1;
	while (!Q.empty()) {
		auto [t, x, y] = Q.top();
		Q.pop();
		if (t > D[x][y])	continue;
		if (arr[x][y] == 'D' && (x == 1 || x == N || y == 1 || y == M))	return cout << t, 0;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx<1 || xx>N || yy<1 || yy>M || arr[xx][yy] == '#')	continue;
			int cost = t + (arr[xx][yy] == 'c');
			if (D[xx][yy] == -1 || D[xx][yy] > cost) {
				D[xx][yy] = cost;
				Q.emplace(cost, xx, yy);
			}
		}
	}

}