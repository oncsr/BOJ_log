#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, dp[502][502]{};
	cin >> n;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			Q.emplace(a, i, j);
		}
	}
	int mx = 0;
	while (!Q.empty()) {
		vector<tuple<int, int, int>> L;
		int cnt = get<0>(Q.top());
		while (!Q.empty() && get<0>(Q.top()) == cnt) {
			L.push_back(Q.top());
			Q.pop();
		}

		vector<tuple<int, int, int>> S;
		for (auto& [h, x, y] : L) {
			int next = 0;
			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d], yy = y + dy[d];
				next = max(next, dp[xx][yy] + 1);
			}
			S.emplace_back(x, y, next);
		}
		
		for (auto& [x, y, h] : S)	dp[x][y] = h, mx = max(mx, dp[x][y]);
	}
	cout << mx;

}