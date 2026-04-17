#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<tuple<int, int, int>> V[501][501]{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;
			if (a == '\\') {
				V[i][j].emplace_back(i + 1, j + 1, 0);
				V[i + 1][j + 1].emplace_back(i, j, 0);
				V[i + 1][j].emplace_back(i, j + 1, 1);
				V[i][j + 1].emplace_back(i + 1, j, 1);
			}
			else {
				V[i][j].emplace_back(i + 1, j + 1, 1);
				V[i + 1][j + 1].emplace_back(i, j, 1);
				V[i + 1][j].emplace_back(i, j + 1, 0);
				V[i][j + 1].emplace_back(i + 1, j, 0);
			}
		}
	}

	vector<vector<int>> D(501, vector<int>(501, -1));
	D[0][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	Q.emplace(D[0][0], 0, 0);
	while (!Q.empty()) {
		auto [dist, x, y] = Q.top();
		Q.pop();
		if (dist > D[x][y])	continue;
		for (auto [xx, yy, cost] : V[x][y]) {
			if (D[xx][yy] == -1 || D[xx][yy] > dist + cost) {
				D[xx][yy] = dist + cost;
				Q.emplace(D[xx][yy], xx, yy);
			}
		}
	}
	if (D[N][M] == -1)	cout << "NO SOLUTION";
	else	cout << D[N][M];

}