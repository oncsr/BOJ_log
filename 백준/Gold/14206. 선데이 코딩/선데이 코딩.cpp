#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll R, S, ans = 0, mod = 1e9 + 7, fac = 1;
vector<vector<ll>> dp(101, vector<ll>(10001, -1));
vector<ll> sum(10001);


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> S;
	if (R == 1)	return cout << 1, 0;
	for (ll i = 1; i < R; i++)	fac = (fac * i) % mod;
	for (int i = R; i <= (R - 1) * S + 1; i++) {
		dp[R][i] = 1;
		sum[i] = sum[i - 1] + 1;
	}
	for (int i = R - 1; i >= 1; i--) {
		for (int j = i; j <= (i - 1) * S + 1; j++) {
			dp[i][j] = (sum[i * S + 1] - sum[j] + mod) % mod;
		}
		for (int j = i; j <= (i - 1) * S + 1; j++) {
			sum[j] = sum[j - 1] + dp[i][j];
		}
	}
	cout << dp[1][1] * R % mod * fac % mod;

}