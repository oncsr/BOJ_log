#include <iostream>
using namespace std;
typedef unsigned long long ll;
#define MOD 1000000007

ll power(ll n, ll r) {
	if (r == 0)
		return 1;
	else {
		ll x = 1;
		ll g = power(n, r / 2) % MOD;
		g = g * g % MOD;
		if (r % 2 == 1)
			return n * g % MOD;
		else
			return g % MOD;
	}
}

int main() {
	ll high = 1;
	ll low = 1;
	ll n, k;
	cin >> n >> k;
	if (k > n / 2)
		k = n - k;
	for (int i = 0; i < k; i++) {
		high *= (n - i);
		high %= MOD;
	}
	for (int i = 1; i <= k; i++) {
		low *= i;
		low %= MOD;
	}
	cout << high * power(low, MOD - 2) % MOD << '\n';
}