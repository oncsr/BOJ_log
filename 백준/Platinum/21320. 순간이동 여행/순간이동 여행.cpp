#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	ll mod = 1e9 + 7;
	if (N == 1)	return cout << 0, 0;
	ll D[3001]{};
	for (int i = 3; i <= 3000; i++) {
		D[i] = 2 * (i - 2);
		for (int j = 1; j <= i - 2; j++) {
			D[i] = (D[i] + 2 * D[j]) % mod;
		}
	}
	ll ans, c;
	if (K == 1)	ans = D[N - 1], c = 1;
	else if (K == N)	ans = 0, c = 0;
	else	ans = 2 * D[N - K], c = 2;
	for (int i = N - K + 1; i <= N - 2; i++) {
		ans = (ans + D[i]) % mod;
		c++;
	}
	for (int i = N - 2; i >= 1; i--) {
		ans = (ans + D[i]) % mod;
		c++;
	}
	ans = (ans + c) % mod;
	cout << ans;

}