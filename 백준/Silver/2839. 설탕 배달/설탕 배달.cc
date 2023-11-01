#include <bits/stdc++.h>
using namespace std;

int fib[1000000]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int dp[5001]{};
	dp[3] = 1, dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		// i킬로그램을 j킬로그램, i-j킬로그램으로 구성하는 경우를 본다.
		for (int j = 3; j < i; j++) {
			// j 혹은 i-j킬로그램을 만들지 못하는 경우는 고려하면 안 된다.
			if (!dp[j] || !dp[i - j])	continue;

			if (!dp[i])	dp[i] = dp[j] + dp[i - j];
			else	dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << (dp[N] == 0 ? -1 : dp[N]);

}