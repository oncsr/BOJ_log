#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll C[5002] = { 1 }, mod = 1000000007;
	for (ll i = 1; i <= 5001; i++) {
		for (ll j = 0; j < i; j++)
			C[i] += C[j] * C[i - 1 - j] % mod;
		C[i] %= mod;
	}
	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		cout << C[n + 1] % mod << '\n';
	}
}