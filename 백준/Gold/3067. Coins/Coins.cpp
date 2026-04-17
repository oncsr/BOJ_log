#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		int dp[10001]{};
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			dp[a]++;
			for (int k = 1; k + a <= 10000; k++) {
				if (dp[k]) {
					dp[k + a] += dp[k];
				}
			}
		}
		int M;
		cin >> M;
		cout << dp[M] << '\n';
	}
	
}