#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, P;
	cin >> N;
	int arr[1001][1001]{}, dp[1001][1001]{}, dp2[1002][1002]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j], dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
	for (int i = N; i >= 1; i--)	for (int j = N; j >= 1; j--)	dp2[i][j] = arr[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
	int ans = 0;
	for (cin >> P; P--;) {
		int x, y;
		cin >> x >> y;
		ans = max(ans, dp[x][y] + dp2[x][y] - arr[x][y]);
	}
	cout << ans;

}