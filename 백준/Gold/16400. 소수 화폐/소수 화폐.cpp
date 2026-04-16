#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, dp[40001]{1}, mod = 123456789;
	cin >> N;
	bitset<40001> e;
	for (int i = 2; i*i <= 40000; i++) if (!e[i]) for (int j = i * i; j <= 40000; j += i) e[j] = 1;
	for (int i = 2; i <= N; i++) if (!e[i]) for (int j = i; j <= N; j++) if (dp[j - i]) dp[j] = (dp[j] + dp[j - i]) % mod;
	cout << dp[N];

}