#include <iostream>
using namespace std;
using ll = long long;
ll dig(ll n) {
	ll ans = 0, m = 1000000000000000000;
	while (n > 0) {
		if (m > n) {
			m /= 10;
			continue;
		}
		ans += (n / m);
		n -= n / m * m;
		m /= 10;
	}
	return ans;
}
int main() {
	ll t, n;
	for (cin >> t; t--;) {
		cin >> n;
		ll temp = n;
		while (temp <= 1000000000000000000 && dig(temp) % 2 == 0) {
			temp *= 3;
		}
		
		if (dig(temp) % 2 == 0) {
			temp = n;
			while (temp <= 1000000000000000000 && dig(temp) % 2 == 0) {
				temp *= 2;
			}
		}

		cout << (temp > 1000000000000000000 ? -1 : temp) << '\n';
		/*
		if (dig(temp) % 2 == 0) {
			cout << "  FAIL NUMBER : " << n << '\n';
		}
		if (n % 1000000 == 0) {
			cout << "CHECKPOINT : " << n << '\n';
		}
		*/
	}
}