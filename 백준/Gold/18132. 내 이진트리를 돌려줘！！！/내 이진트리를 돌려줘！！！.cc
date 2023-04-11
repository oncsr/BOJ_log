#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		ll C[5002] = { 1 }, mod = 1000000007;
		for (ll i = 1; i <= n + 1; i++) {
			for (ll j = 0; j < i; j++)
				C[i] += C[j] * C[i - 1 - j] % mod;
			C[i] %= mod;
		}
		cout << C[n + 1] % mod << '\n';
	}
}