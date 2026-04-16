#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T, INF = -1e9;
	cin >> N >> T;
	int dist[201][201]{}, dp[201][1001]{}, C[201]{}, E[201]{};
	
	for (int i = 1; i <= N; i++) cin >> C[i] >> E[i], dp[i][0] = C[i] == 0 ? 0 : INF;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> dist[i][j];
	for (int i = 1; i <= N; i++) for (int t = 1; t <= T; t++) dp[i][t] = INF;
	int ans = 0;
	for (int t = 1; t <= T; t++) {
		for (int n = 1; n <= N; n++) {
			if (dp[n][t - 1] != INF) dp[n][t] = max(dp[n][t], dp[n][t - 1] + E[n]);
			for (int i = 1; i <= N; i++) if (i != n && t - dist[i][n] >= 0 && dp[i][t - dist[i][n]] >= C[n]) dp[n][t] = max(dp[n][t], dp[i][t - dist[i][n]]);
			if (t == T) ans = max(ans, dp[n][t]);
		}
	}
	cout << ans;

}