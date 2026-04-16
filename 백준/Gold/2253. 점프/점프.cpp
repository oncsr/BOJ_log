#include <bits/stdc++.h>
using namespace std;

int N, M;
bitset<11111> wall;
vector<vector<int>> dp(11111, vector<int>(222, -1));

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int a; M--; wall[a] = 1) cin >> a;

	if (!wall[2]) dp[2][1] = 1;
	for (int i = 2; i < N; i++) for (int x = 1; x < 222; x++) if (dp[i][x] != -1) {
		if (!wall[i + x + 1] && x < 221) {
			int& res = dp[i + x + 1][x + 1];
			if (res == -1) res = dp[i][x] + 1;
			else res = min(res, dp[i][x] + 1);
		}
		if (!wall[i+x]) {
			int& res = dp[i + x][x];
			if (res == -1) res = dp[i][x] + 1;
			else res = min(res, dp[i][x] + 1);
		}
		if (x > 1 && !wall[i + x - 1]) {
			int& res = dp[i + x - 1][x - 1];
			if (res == -1) res = dp[i][x] + 1;
			else res = min(res, dp[i][x] + 1);
		}
	}
	int ans = 123456;
	for (int x = 1; x < 222; x++) if (dp[N][x] != -1) ans = min(ans, dp[N][x]);
	cout << (ans == 123456 ? -1 : ans);

}