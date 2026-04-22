#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	int dp[500][500]{}, temp[500]{};
	int mn = 10001, mn2 = 10001;
	for (int i = 0; i < M; i++) {
		cin >> dp[0][i];
		if (dp[0][i] < mn)	mn2 = mn, mn = dp[0][i];
		else if (dp[0][i] < mn2)	mn2 = dp[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> dp[i][j];
			if (dp[i - 1][j] == mn)	dp[i][j] += mn2;
			else	dp[i][j] += mn;
		}
		mn = 5000001, mn2 = 5000001;
		for (int j = 0; j < M; j++) {
			if (dp[i][j] < mn)	mn2 = mn, mn = dp[i][j];
			else if (dp[i][j] < mn2)	mn2 = dp[i][j];
		}
	}
	int ans = 5000001;
	for (int i = 0; i < M; i++)	ans = min(ans, dp[N - 1][i]);
	cout << ans;
}