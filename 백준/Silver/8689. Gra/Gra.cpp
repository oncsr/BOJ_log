#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, dp[1000001]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		if (i == 1)	continue;
		int mx = -100001;
		for (int j = i - 1; j >= max(i - 6, 1); j--)	mx = max(mx, dp[j]);
		dp[i] += mx;
	}
	cout << dp[N];
}