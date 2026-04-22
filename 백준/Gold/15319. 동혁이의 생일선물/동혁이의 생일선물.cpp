#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll power(ll a, ll b) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	ll part = power(a, b / 2) % mod;
	if (b % 2)	return (part * part % mod) * a % mod;
	return part * part % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ll ans = 0;
	for (cin >> N; N--;) {
		ll x, K, g = (1LL << 30), b = 30;
		cin >> x >> K;
		while (g > 1) {
			if (K % g >= (g / 2))
				ans = (ans + power(x, b - 1)) % mod;
			b--;
			g /= 2;
		}
	}
	cout << ans;
}