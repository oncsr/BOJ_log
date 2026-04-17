#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	auto etf = [](ll n) -> ll {
		ll res = n;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i)	continue;
			while (n % i == 0)	n /= i;
			res *= (i - 1);
			res /= i;
		}
		if (n > 1) {
			res *= (n - 1);
			res /= n;
		}
		return res;
	};

	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		if (n == 1) { cout << "0\n"; continue; }
		if (n == 2) { cout << "1\n"; continue; }
		ll ans = etf(n);
		if (n % 2 == 0)	ans += etf(n / 2);
		cout << ans << '\n';
	}

}