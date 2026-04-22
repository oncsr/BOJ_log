#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll mod = 1000000007LL, T;
	for (cin >> T; T--;) {
		ll A, B, N;
		cin >> A >> B >> N;
		ll f[6] = { A - B, A, B, B - A, -A, -B };
		N %= 6;
		cout << (f[N] + mod * 10) % mod << '\n';
	}
}