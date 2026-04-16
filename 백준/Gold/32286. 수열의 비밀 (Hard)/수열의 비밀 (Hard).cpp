#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll k, p, q, r, s, a, m = 1e9+7, g = 1;
	cin >> k >> p >> q >> r >> s >> a;
	ll ans = a, S = a;
	for (int i = 2; i <= k; i++) {
		ans += S = ((S * (p + r)) % m + (g * (q + s)) % m) % m;
		ans %= m;
		g <<= 1;
	}
	cout << ans;

}