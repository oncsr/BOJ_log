#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, n;
	ll C[2501] = { 1 }, mod = 1000000007;
	for (ll i = 1; i <= 2500; i++) {
		for (ll j = 0; j < i; j++)
			C[i] += C[j] * C[i - 1 - j] % mod;
		C[i] %= mod;
	}
	for (cin >> t; t--;) {
		cin >> n;
		if (n % 2)	cout << "0\n";
		else	cout << C[n / 2] % mod << '\n';
	}
}