#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F(ll n) {
	if (n <= 2)	return n;
	ll s = 1;
	while (s < n)	s <<= 1;
	s >>= 1;
	ll p = F(n - s / 2);
	if (n > s * 3 / 2)	return p * 2;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ll K;
		cin >> K;
		cout << F(K) << '\n';
	}

}