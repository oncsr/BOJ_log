#include <iostream>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll power(ll a, ll b) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	ll p = power(a, b / 2);
	p = p * p % mod;
	if (b & 1)	return p * a % mod;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll M, s = 0;
	for (cin >> M; M--;) {
		ll a, b;
		cin >> a >> b;
		s = (s + b % mod * power(a, mod - 2) % mod) % mod;
	}
	cout << s;
}