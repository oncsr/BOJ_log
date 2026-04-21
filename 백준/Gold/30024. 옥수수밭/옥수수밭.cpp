#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int find[1000][1000]{}, N, M, K;
	ll arr[1000][1000]{};
	priority_queue<tuple<ll, int, int>> Q;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (!i || i == N - 1 || !j || j == M - 1)	find[i][j] = 1, Q.push({ arr[i][j], i, j });
		}
	}
	cin >> K;
	vector<ii> ans;
	while (K--) {
		auto [v, x, y] = Q.top();
		Q.pop();
		ans.push_back({ x,y });
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < N && yy >= 0 && yy < M && !find[xx][yy]) {
				find[xx][yy] = 1;
				Q.push({ arr[xx][yy], xx, yy });
			}
		}
	}
	for (auto [x, y] : ans)	cout << x + 1 << ' ' << y + 1 << '\n';
}