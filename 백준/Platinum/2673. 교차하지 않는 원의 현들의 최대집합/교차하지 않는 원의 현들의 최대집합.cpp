#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int dp[101][101]{}, exist[101][101]{};
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)	swap(a, b);
		exist[a][b] = exist[b][a] = 1;
	}
	for (int k = 1; k < 100; k++) {
		for (int i = 1; i <= 100; i++) {
			// i ~ i+k
			int j = (i + k) % 100 == 0 ? 100 : (i + k) % 100;
			dp[i][j] = max(dp[i][j], exist[i][j]);
			dp[j][i] = max(dp[j][i], exist[i][j]);
			for (int d = i + 1; d < i + k; d++) {
				int dd = d % 100 == 0 ? 100 : d % 100;
				dp[i][j] = max(dp[i][j], dp[i][dd] + dp[dd][j] + exist[i][j]);
			}
			for (int d = j + 1; d < i + (j < i ? 0 : 100); d++) {
				int dd = d % 100 == 0 ? 100 : d % 100;
				dp[j][i] = max(dp[j][i], dp[j][dd] + dp[dd][i] + exist[i][j]);
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j)	continue;
			mx = max(mx, dp[i][j] + dp[j][i] - exist[i][j]);
		}
	}
	cout << mx << '\n';

}