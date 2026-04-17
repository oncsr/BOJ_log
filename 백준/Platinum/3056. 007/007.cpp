#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int N;
ld dp[1 << 20]{};
ld cost[20][20]{};

ld sol(int n, int k) {
	if (n == 0)	dp[k] = 100;
	if (dp[k])	return dp[k];
	for (int i = 0; i < N; i++) {
		if (!(k & (1 << i)))	continue;
		int next = k ^ (1 << i);
		if (!dp[k])	dp[k] = sol(n - 1, next) * cost[n - 1][i];
		else	dp[k] = max(dp[k], sol(n - 1, next) * cost[n - 1][i]);
	}
	return dp[k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> cost[i][j];
	cout.precision(6);
	cout << fixed << sol(N, (1 << N) - 1) / pow(100, N);

}