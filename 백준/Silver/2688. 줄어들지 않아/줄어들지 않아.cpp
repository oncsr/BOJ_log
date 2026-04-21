#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll dp[65][11]{};
	for (int i = 0; i < 10; i++)	dp[1][i] = 1;
	dp[1][10] = 10;
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++)
			for (int k = j; k < 10; k++)
				dp[i][j] += dp[i - 1][k];
		for (int j = 0; j < 10; j++)	dp[i][10] += dp[i][j];
	}

	int t;
	for (cin >> t; t--;) {
		int n;
		cin >> n;
		cout << dp[n][10] << '\n';
	}
	

}