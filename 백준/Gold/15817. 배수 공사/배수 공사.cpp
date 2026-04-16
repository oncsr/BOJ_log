#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dp[10001]{}, N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		int new_dp[10001]{};
		for (int j = X; j > 0; j--) {
			if (!dp[j])	continue;
			for (int k = 0; k <= b && j + k * a <= X; k++) {
				new_dp[j + k * a] += dp[j];
			}
		}
		for (int k = 1; k <= b && k * a <= X; k++)	new_dp[k * a]++;
		for (int j = 0; j <= X; j++)	dp[j] = new_dp[j];

	}
	cout << dp[X];

}