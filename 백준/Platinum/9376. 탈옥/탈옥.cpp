#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int N, M;
char arr[100][100]{};
vector<vector<int>> A, B, C;
deque<tuple<int, int, int>> q;
int ax = -1, ay = -1, bx = -1, by = -1;

void bfs01(vector<vector<int>> &D) {
	while (!q.empty()) {
		auto [x, y, d] = q.front(); q.pop_front();
		if (d > D[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M || arr[xx][yy] == '*') continue;
			int cost = arr[xx][yy] == '#' ? 1 : 0;
			if (D[xx][yy] > d + cost) {
				D[xx][yy] = d + cost;
				if (cost) q.emplace_back(xx, yy, d + cost);
				else q.emplace_front(xx, yy, d + cost);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ax = -1, ay = -1, bx = -1, by = -1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '$') {
				if (ax == -1) ax = i, ay = j;
				else bx = i, by = j;
			}
		}
		A = vector<vector<int>>(N, vector<int>(M, INF));
		B = vector<vector<int>>(N, vector<int>(M, INF));
		C = vector<vector<int>>(N, vector<int>(M, INF));

		q.emplace_back(ax, ay, 0);
		A[ax][ay] = 0;
		bfs01(A);

		q.emplace_back(bx, by, 0);
		B[bx][by] = 0;
		bfs01(B);

		for (int i = 0; i < M; i++) {
			if (arr[0][i] != '*') {
				int cost = arr[0][i] == '#' ? 1 : 0;
				C[0][i] = cost;
				if (cost) q.emplace_back(0, i, cost);
				else q.emplace_front(0, i, cost);
			}
			if (arr[N - 1][i] != '*') {
				int cost = arr[N - 1][i] == '#' ? 1 : 0;
				C[N - 1][i] = cost;
				if (cost) q.emplace_back(N - 1, i, cost);
				else q.emplace_front(N - 1, i, cost);
			}
		}
		for (int i = 0; i < N; i++) {
			if (arr[i][0] != '*') {
				int cost = arr[i][0] == '#' ? 1 : 0;
				C[i][0] = cost;
				if (cost) q.emplace_back(i, 0, cost);
				else q.emplace_front(i, 0, cost);
			}
			if (arr[i][M - 1] != '*') {
				int cost = arr[i][M - 1] == '#' ? 1 : 0;
				C[i][M - 1] = cost;
				if (cost) q.emplace_back(i, M - 1, cost);
				else q.emplace_front(i, M - 1, cost);
			}
		}
		bfs01(C);

		int aMin = INF, bMin = INF;
		for (int i = 0; i < N; i++) {
			aMin = min({ aMin, A[i][0], A[i][M - 1] });
			bMin = min({ bMin, B[i][0], B[i][M - 1] });
		}
		for (int j = 0; j < M; j++) {
			aMin = min({ aMin, A[0][j], A[N - 1][j] });
			bMin = min({ bMin, B[0][j], B[N - 1][j] });
		}
		int ans = aMin + bMin;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j] != '*') {
			int to = A[i][j] + B[i][j] - (arr[i][j] == '#' ? 1 : 0);
			int from = C[i][j];
			if (to >= INF || from >= INF) continue;
			ans = min(ans, to + from - (arr[i][j] == '#' ? 1 : 0));
		}
		cout << ans << '\n';
	}

}