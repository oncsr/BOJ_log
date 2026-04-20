#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dp[1001][2]{};
	int N;
	int arr[1001][2]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		arr[i][0] = x, arr[i][1] = y;
		if (i == 1)	dp[i][0] = x, dp[i][1] = y;
		else {
			dp[i][0] = max(dp[i - 1][0] + abs(arr[i - 1][1] - arr[i][1]) + arr[i][0], dp[i - 1][1] + abs(arr[i - 1][0] - arr[i][1]) + arr[i][0]);
			dp[i][1] = max(dp[i - 1][0] + abs(arr[i - 1][1] - arr[i][0]) + arr[i][1], dp[i - 1][1] + abs(arr[i - 1][0] - arr[i][0]) + arr[i][1]);
		}
	}
	cout << max(dp[N][0], dp[N][1]);
}