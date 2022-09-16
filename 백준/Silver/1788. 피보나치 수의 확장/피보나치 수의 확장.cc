#include <iostream>
using namespace std;
constexpr auto mod = 1000000000;
int main() {
	int dp[1000001]{};
	dp[0] = 0, dp[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= abs(n); i++)	dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
	if (n < 0) {
		n *= -1;
		cout << (n % 2 ? 1 : -1) << '\n';
		cout << dp[n];
	}
	else {
		cout << (n ? 1 : 0) << '\n';
		cout << dp[n];
	}
}