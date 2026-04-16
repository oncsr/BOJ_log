#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> arr[50][50]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--, c--;
		arr[r][c].emplace_back(m, s, d);
	}

	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

	for (; K--;) {
		vector<tuple<int, int, int, int, int>> info;
		for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++) {
			while (!arr[i][j].empty()) {
				auto& [m, s, d] = arr[i][j].back();
				arr[i][j].pop_back();
				int x = (i + s * dx[d] + 1000000 * N) % N, y = (j + s * dy[d] + 1000000 * N) % N;
				info.emplace_back(x, y, m, s, d);
			}
		}

		for (auto& [x, y, m, s, d] : info)	arr[x][y].emplace_back(m, s, d);
		for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++) {
			if (arr[i][j].size() <= 1)	continue;
			int ms = 0, ss = 0, even = 0, odd = 0, cnt = arr[i][j].size();
			while (!arr[i][j].empty()) {
				auto& [m, s, d] = arr[i][j].back();
				arr[i][j].pop_back();
				ms += m, ss += s;
				even += d % 2 == 0;
				odd += d % 2 == 1;
			}

			int dir = (even && odd) ? 1 : 0;
			ms /= 5, ss /= cnt;
			if (!ms)	continue;
			for (int k = 0; k < 4; k++) {
				arr[i][j].emplace_back(ms, ss, dir + 2 * k);
			}

		}

	}

	int ans = 0;
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	for (auto& [m, s, d] : arr[i][j]) {
		ans += m;
	}
	cout << ans;

}