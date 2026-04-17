#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	int cost[10][10]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> cost[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}
	}

	int dp[10][1 << 10]{};
	fill(dp[0], dp[0] + 10 * 1024, -1);
	function<int(int, int)> bck = [&](int n, int v) -> int {
		int k = v - (1 << n);
		if (!k)	return n == K ? 0 : 1e9;
		for (int i = 0; i < N; i++) {
			if (!((1 << i) & k))	continue;
			if (dp[i][k] == -1)	dp[i][k] = bck(i, k);
			if (dp[n][v] == -1)	dp[n][v] = dp[i][k] + cost[i][n];
			else	dp[n][v] = min(dp[n][v], dp[i][k] + cost[i][n]);
		}
		return dp[n][v];
	};

	int ans = 1e9;
	for (int i = 0; i < N; i++)	ans = min(ans, bck(i, (1 << N) - 1));
	cout << ans;

}