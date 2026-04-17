#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(20, vector<int>(1 << 20, -1));
int A[21]{}, B[20]{};
int N, M;

int sol(int n, int k, int need) {
	if (n == N)	return 1;
	if (dp[n][k] != -1)	return dp[n][k];
	dp[n][k] = 0;
	for (int i = 0; i < M; i++) {
		if (k & (1 << i))	continue;
		if (need - B[i] == 0)	dp[n][k] |= sol(n + 1, k | (1 << i), A[n + 1]);
		else if (need - B[i] > 0)	dp[n][k] |= sol(n, k | (1 << i), need - B[i]);
	}
	return dp[n][k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> A[i];
	for (int i = 0; i < M; i++)	cin >> B[i];
	
	cout << (sol(0, 0, A[0]) ? "YES" : "NO");

}