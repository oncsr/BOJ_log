#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K, mod = 1e9 + 3;
	cin >> N >> K;
	if (2 * K - 1 > N) { cout << 0; return 0; }
	
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	vector<vector<ll>> dp2(N + 1, vector<ll>(N + 1));

	vector<ll> pre(N + 1);
	vector<ll> pre2(N + 1);
	for (int i = 1; i <= N; i++) {
		dp[1][i] = 1, dp2[1][i] = (i == 1);
		pre[i] = pre[i - 1] + dp[1][i];
		pre2[i] = pre2[i - 1] + dp2[1][i];
	}

	for (int k = 2; k <= K; k++) {
		vector<ll> new_pre(N + 1);
		vector<ll> new_pre2(N + 1);
		for (int g = 2 * k - 1; g <= N; g++) {
			dp[k][g] = pre[g - 2] - pre[2 * k - 4];
			dp[k][g] %= mod;
			new_pre[g] = new_pre[g - 1] + dp[k][g];
			new_pre[g] %= mod;
			dp2[k][g] = pre2[g - 2] - pre2[2 * k - 4];
			dp2[k][g] %= mod;
			new_pre2[g] = new_pre2[g - 1] + dp2[k][g];
			new_pre2[g] %= mod;
		}
		pre = new_pre;
		pre2 = new_pre2;
	}

	ll ans = 0;
	for (int i = 2 * K - 1; i <= N; i++)	ans = (ans + dp[K][i]) % mod;
	ans = (ans - dp2[K][N] + mod) % mod;
	cout << ans;



}