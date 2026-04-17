#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K, a, b, c, d;
	cin >> N >> K >> a >> b >> c >> d;
	vector<int> dp(K + 1, -1);
	dp[a] = b, dp[c] = max(dp[c], d);
	for (int i = 1; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<int> dp2(K + 1, -1);
		for (int j = K - a; j >= 0; j--)	if (dp[j] != -1)	dp2[j + a] = max(dp2[j + a], dp[j] + b);
		for (int j = K - c; j >= 0; j--)	if (dp[j] != -1)	dp2[j + c] = max(dp2[j + c], dp[j] + d);
		dp = dp2;
	}
	cout << *max_element(dp.begin(), dp.begin() + K + 1);

}