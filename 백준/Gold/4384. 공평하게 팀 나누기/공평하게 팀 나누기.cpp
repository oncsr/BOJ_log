#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int dp[45001][101]{}, S = 0;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		S += a;
		for (int k = i - 1; k >= 1; k--) {
			for (int j = 450 * k; j > 0; j--) {
				if (dp[j][k])	dp[j + a][k + 1] = 1;
			}
		}
		dp[a][1] = 1;
	}

	int mx = 0, p = N / 2, q = (N & 1) ? (N + 1) / 2 : N / 2;
	for (int j = 1; j <= 45000; j++) {
		if (dp[j][p]) {
			if (j <= S / 2 && j > mx)	mx = j;
		}
		if (dp[j][q]) {
			if (j <= S / 2 && j > mx)	mx = j;
		}
	}
	cout << mx << ' ' << S - mx;

}