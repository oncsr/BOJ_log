#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	char arr[1000][1000]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];

	map<char, pair<int, int>> dir;
	dir['D'] = { 1,0 };
	dir['R'] = { 0,1 };
	dir['L'] = { 0,-1 };
	dir['U'] = { -1,0 };
	int vis[1000][1000]{};
	int ans = 0, num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j])	continue;
			vector<pair<int, int>> V;
			V.emplace_back(i, j);
			auto [dx, dy] = dir[arr[i][j]];
			vis[i][j] = num;
			int x = i + dx, y = j + dy;
			while (!vis[x][y]) {
				V.emplace_back(x, y);
				vis[x][y] = num;
				auto [dx, dy] = dir[arr[x][y]];
				x += dx, y += dy;
			}
			if (vis[x][y] == num)	ans++, num++;
			else {
				for (auto [a, b] : V)	vis[a][b] = vis[x][y];
			}
		}
	}
	cout << ans;

}