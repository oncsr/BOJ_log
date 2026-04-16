#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1'000'003LL;
ll power(ll n, ll k) {
	if (k == 0)	return 1;
	if (k == 1)	return n % mod;
	ll p = power(n, k >> 1);
	if (k & 1)	return p * p % mod * n % mod;
	return p * p % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll k;
	cin >> k;
	cout << (((power(2, 2 * k - 1) + 1) % mod * power(3, mod - 2)) % mod + (mod - power(2, k - 1)) % mod) % mod;

}