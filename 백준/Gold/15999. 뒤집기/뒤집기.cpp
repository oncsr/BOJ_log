#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	ll ans = 1, mod = 1e9 + 7;
	char arr[2000][2000]{};
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)	cin >> arr[i][j];

	bool vis[2000][2000]{};
	bool ch[2000][2000]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	bool vis2[2000][2000]{};
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) {
		if (vis[i][j])	continue;
		queue<pair<int, int>> Q;
		vector<pair<int, int>> V;
		Q.emplace(i, j);
		vis[i][j] = 1;
		ch[i][j] = 1;
		while (!Q.empty()) {
			auto [x, y] = Q.front(); Q.pop();
			V.emplace_back(x, y);
			ch[x][y] = 1;
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k], yy = y + dy[k];
				if (xx < 0 || xx >= N || yy < 0 || yy >= M)	continue;
				if (arr[xx][yy] != arr[x][y]) { ch[x][y] = 0; continue; }
				if (vis[xx][yy])	continue;
				vis[xx][yy] = 1;
				Q.emplace(xx, yy);
			}
		}
		for (auto& [a, b] : V) {
			if (!ch[a][b] || vis2[a][b])	continue;
			vis2[a][b] = 1;
			ll r = 1;
			Q.emplace(a, b);
			while (!Q.empty()) {
				auto [x, y] = Q.front(); Q.pop();
				r = (r * 2) % mod;
				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k], yy = y + dy[k];
					if (xx < 0 || xx >= N || yy < 0 || yy >= M)	continue;
					if (vis2[xx][yy] || !ch[xx][yy])	continue;
					Q.emplace(xx, yy);
					vis2[xx][yy] = 1;
				}
			}
			ans = (ans * r) % mod;
		}
		
	}
	cout << ans;


}