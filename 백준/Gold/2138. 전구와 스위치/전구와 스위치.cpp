#include <iostream>
#include <algorithm>
using namespace std;

int A[100002]{}, B[100002]{}, N, dp[100002][8]{}, INF = 1e9;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		char a;
		cin >> a;
		A[i] = a - '0';
	}
	for (int i = 1; i <= N; i++) {
		char a;
		cin >> a;
		B[i] = a - '0';
	}

	for (int i = 0; i <= N + 1; i++) for (int j = 0; j < 8; j++) dp[i][j] = INF;
	dp[2][(2 * A[1]) | (1 * A[2])] = 0;
	dp[2][4 | (2 * A[1]) | (1 * A[2])] = 0;
	dp[2][((2 * A[1]) | (1 * A[2])) ^ 7] = 1;
	dp[2][(4 | (2 * A[1]) | (1 * A[2])) ^ 7] = 1;
	for (int i = 3; i <= N + 1; i++) for (int k = 0; k < 8; k++) {
		if ((k & 1) == A[i]) dp[i][k] = dp[i - 1][(k >> 1) | (4 * B[i - 3])];
		else dp[i][k] = dp[i - 1][((k ^ 6) >> 1) | (4 * B[i - 3])] + 1;
	}
	int ans = min(dp[N + 1][(4 * B[N - 1]) | (2 * B[N])], dp[N + 1][(4 * B[N - 1]) | (2 * B[N]) | 1]);
	cout << (ans >= INF ? -1 : ans);

}