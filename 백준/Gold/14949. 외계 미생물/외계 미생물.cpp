#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7, x, y, C[401][401]{}, dp[6][201]{};

ll H(ll a, ll b) {
	return C[a + b - 1][a];
}

ll F(ll h, ll w) {
	if (h == 1)	return dp[h][w] = 1;
	if (dp[h][w])	return dp[h][w];
	for (int i = 1; i <= y; i++) {
		dp[h][w] = (dp[h][w] + F(h - 1, i) * H(i, w)) % mod;
	}
	return dp[h][w];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 400; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}

	cin >> x >> y;
	if (x == 0)	return cout << 1, 0;
	ll ans = 0;
	for (int i = 1; i <= y; i++)	ans = (ans + F(x, i)) % mod;
	cout << ans;

}