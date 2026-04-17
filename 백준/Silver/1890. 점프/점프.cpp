#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;

	int arr[101][101]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j];

	long long dp[111][111]{};
	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == 0 || arr[i][j] == 0)	continue;

			int right = j + arr[i][j];
			int down = i + arr[i][j];

			dp[i][right] += dp[i][j];
			dp[down][j] += dp[i][j];

		}
	}

	cout << dp[N][N];

}