#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll power(ll x, ll n) {
	if (n == 0)	return 1;
	ll p = power(x, n / 2);
	ll res = p * p % mod;
	if (n % 2)	res = res * x % mod;
	return res;
}

int main() {
	ll N, a, b;
	cin >> N;
	ll r = 0;
	while (N--) {
		cin >> a >> b;
		if (b == 0)	continue;
		r = r + (a * b % mod * power(2, b - 1) % mod);
	}
	cout << r % mod;
}