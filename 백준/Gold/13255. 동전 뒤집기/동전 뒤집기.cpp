#include <bits/stdc++.h>
using namespace std;
using ld = long double;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	ld comb[1001][1001]{};
	comb[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

	int N, K, A[50]{};
	cin >> N >> K;

	for (int i = 0; i < K; i++)	cin >> A[i];

	ld dp[1001]{};
	dp[N] = 1;
	for (int i = 0; i < K; i++) {
		ld new_dp[1001]{};
		for (int j = 0; j <= N; j++) {
			for (int x = 0; x <= A[i]; x++) {
				if (j < x || N - j < A[i] - x)	continue;
				ld v = dp[j] * comb[j][x] * comb[N - j][A[i] - x] / comb[N][A[i]];
				new_dp[j + A[i] - 2 * x] += v;
			}
		}
		for (int j = 0; j <= N; j++)	dp[j] = new_dp[j];
	}

	ld ans = 0;
	for (int i = 0; i <= N; i++)	ans += dp[i] * i;
	cout.precision(10);
	cout << fixed << ans;

}