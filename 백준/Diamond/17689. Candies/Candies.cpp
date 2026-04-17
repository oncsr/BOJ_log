#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(((N + 1) >> 1) + 1));
	vector<ll> arr(N + 1);
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (int k = 1; k <= (N + 1) / 2; k++) {
		for (int i = 2 * k - 1; i <= N; i++) {
			dp[i][k] = dp[i - 1][k];
			dp[i][k] = max(dp[i][k], (i > 1 ? dp[i - 2][k - 1] : 0) + arr[i]);
		}
	}
	for (int k = 1; k <= (N + 1) >> 1; k++) {
		cout << dp[N][k] << '\n';
	}

}