#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int H, W, N, vis[20][20][20]{};
	cin >> H >> W;
	queue<tuple<int, int, int, string>> Q;
	char arr[20][20]{};

	for (int i = 0; i < H; i++)	for (int j = 0; j < W; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'D') {
			vis[i][j][0]++;
			Q.emplace(i, j, 0, "");
		}
	}

	cin >> N;
	vector<pair<char, char>> M(N);
	for (auto& [a, b] : M)	cin >> a >> b;

	auto move = [&](int x, int y, char d, int t, string r) -> void {
		if (d == 'W')	x--;
		if (d == 'A')	y--;
		if (d == 'S')	x++;
		if (d == 'D')	y++;
		if (x < 0 || x >= H || y < 0 || y >= W || vis[x][y][t + 1] || arr[x][y] == '@')	return;
		Q.emplace(x, y, t + 1, r + d);
		vis[x][y][t + 1]++;
	};

	while (!Q.empty()) {
		auto [x, y, t, r] = Q.front();
		Q.pop();
		if (arr[x][y] == 'Z')	return cout << "YES\n" << r, 0;
		if (t == N)	continue;
		auto [i, j] = M[t];
		move(x, y, i, t, r);
		move(x, y, j, t, r);
	}
	cout << "NO";

}