#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int TC;
	for (cin >> TC; TC--;) {
		int N;
		cin >> N;
		vector<int> arr(N + 1);
		vector<int> sum(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			sum[i] = arr[i] + sum[i - 1];
		}

		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		
		for (int interval = 1; interval < N; interval++) {

			for (int i = 1, j = interval + 1; j <= N; i++, j++) {
				for (int k = i; k < j; k++) {

					int res = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
					if (!dp[i][j] || res < dp[i][j])	dp[i][j] = res;

				}
			}

		}
		cout << dp[1][N] << '\n';
	}

}