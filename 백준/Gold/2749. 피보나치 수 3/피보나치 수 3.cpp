#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000;

map<ll, ll> M;

ll fib(ll n) {
	if (M[n])	return M[n];
	if (n == 0)	return M[n] = 0;
	if (n == 1)	return M[n] = 1;
	if (!M[n >> 1])	M[n >> 1] = fib(n >> 1);
	if (n & 1) {
		if (!M[(n >> 1) + 1])	M[(n >> 1) + 1] = fib((n >> 1) + 1);
		return M[n] = (M[n >> 1] * M[n >> 1] + M[(n >> 1) + 1] * M[(n >> 1) + 1]) % mod;
	}
	if (!M[(n >> 1) - 1])	M[(n >> 1) - 1] = fib((n >> 1) - 1);
	return M[n] = (M[n >> 1] * (2 * M[(n >> 1) - 1] + M[n >> 1])) % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin >> n;
	cout << fib(n);

}