#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll dp[501][501]{};
	ll sum[501][501]{};
	dp[1][0] = 1, dp[2][1] = 1;
	
	int N, E;
	cin >> N >> E;

	for (int i = 1; i <= N; i++) {
		if (i >= 3) {
			for (int j = 0; j < i; j++) {
				if (j)	dp[i][j] = dp[i - 1][j - 1];
			
				for (int x = 1; x < i - 1; x++) {
					ll G1 = dp[x][j] * (sum[i - x - 1][500] - sum[i - x - 1][j] + mod) % mod;
					ll G2 = dp[i - x - 1][j] * (sum[x][500] - sum[x][j] + mod) % mod;
					ll G3 = dp[x][j] * dp[i - x - 1][j] % mod;
					dp[i][j] = (dp[i][j] + G1 + G2 + G3) % mod;
				}

			}
		}
		for (int j = 0; j <= 500; j++) {
			if (!j)	sum[i][j] = dp[i][j];
			else	sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
		}
	}
	cout << dp[N][E];
	
}