#include <iostream>
using namespace std;
using ll = long long;

ll x, mod = 1e9 + 7;
ll P(ll n) {
	if (n == 0)	return 1;
	if (n == 1)	return x;
	ll p = P(n / 2);
	p = p * p % mod;
	if (n & 1)	return p * x % mod;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N >> x;
	ll s = 0;
	for (int i = 0; i < N + 1; i++) {
		ll a, b;
		cin >> a >> b;
		s = (s + a * P(b) % mod) % mod;
	}
	cout << s;
}