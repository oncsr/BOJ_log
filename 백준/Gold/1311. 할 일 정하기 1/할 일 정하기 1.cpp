#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20]{};
int arr[20][20]{};
int N;

int DP(int n, int k) {
	if (dp[k])	return dp[k];
	for (int i = 0; i < N; i++) {
		if (!(k & (1 << i)))	continue;
		int next = k ^ (1 << i);
		if (!dp[k])	dp[k] = DP(n - 1, next) + arr[n - 1][i];
		else	dp[k] = min(dp[k], DP(n - 1, next) + arr[n - 1][i]);
	}
	return dp[k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> arr[i][j];
	cout << DP(N, (1 << N) - 1);

}