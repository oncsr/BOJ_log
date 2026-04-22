#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll power(ll a, ll b) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	ll p = power(a, b / 2);
	p = p * p % mod;
	if (b % 2)	return p * a % mod;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, i = 2, s = 1;
	cin >> n >> m;
	while (n > 1 && i * i <= n) {
		ll t = 0;
		while (n % i == 0) {
			n /= i;
			t++;
		}

		if (t) {
			s = s * (power(i, t * m + 1) - 1) % mod * power(i - 1, mod - 2) % mod;
		}

		i++;
	}
	if (n > 1)	s = s * (power(n, m + 1) - 1) % mod * power(n - 1, mod - 2) % mod;
	cout << s;
}