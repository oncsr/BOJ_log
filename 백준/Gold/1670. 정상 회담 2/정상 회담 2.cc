#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	ll C[5001] = { 1 }, mod = 987654321;
	for (ll i = 1; i <= n / 2; i++) {
		for (ll j = 0; j < i; j++)
			C[i] += C[j] * C[i - 1 - j] % mod;
		C[i] %= mod;
	}
	cout << C[n / 2] % mod;
}