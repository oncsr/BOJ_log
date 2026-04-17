#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	int dp[10001]{};
	for (int i = 0; i < K; i++) {
		int l, t;
		cin >> l >> t;
		for (int j = 10000; j > t; j--) {
			if (dp[j - t])	dp[j] = max(dp[j], dp[j - t] + l);
		}
		dp[t] = max(dp[t], l);
	}
	int mx = 0;
	for (int i = 0; i <= N; i++)	mx = max(mx, dp[i]);
	cout << mx;

}
