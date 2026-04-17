#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t, w;
	cin >> t >> w;
	int dp[1001][3][31]{};
	
	for (int i = 1; i <= t; i++) {
		int a;
		cin >> a;
		int b = a == 1 ? 2 : 1;
		if (a == 1) {
			dp[i][a][0] = dp[i - 1][a][0] + 1;
		}
		dp[i][b][0] = dp[i - 1][b][0];
		for (int j = 1; j <= w; j++) {
			dp[i][a][j] = max(dp[i - 1][a][j], dp[i - 1][b][j - 1]) + 1;
			dp[i][b][j] = dp[i - 1][b][j];
		}
	}
	int mx = 0;
	for (int i = 0; i <= w; i++)	mx = max({ mx, dp[t][1][i], dp[t][2][i] });
	cout << mx;
	
}