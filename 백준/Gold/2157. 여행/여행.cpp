#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	vector<vector<int>> dp(301, vector<int>(301, -1));
	vector<vector<pair<int, int>>> V(301);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)	continue;
		V[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < min(M, i); j++) {
			for (auto e : V[i]) {
				int k = e.first, c = e.second;
				if (j > 1) {
					if (dp[k][j - 1] == -1)	continue;
					dp[i][j] = max(dp[i][j], dp[k][j - 1] + c);
				}
				else {
					if (k != 1)	continue;
					dp[i][j] = max(dp[i][j], c);
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i < M; i++)	ans = max(ans, dp[N][i]);
	cout << ans;
}