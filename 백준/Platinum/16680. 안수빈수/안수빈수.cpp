#include <iostream>
using namespace std;
using ll = long long;
const ll MAX = 1000000000000000000;

ll dig(ll n) {
	ll ans = 0, m = MAX;
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
		while (temp <= MAX && dig(temp) % 2 == 0) {
			temp *= 3;
		}
		if (dig(temp) % 2 == 0) {
			temp = n;
			while (temp <= MAX && dig(temp) % 2 == 0) {
				temp *= 2;
			}
		}
		cout << temp << '\n';
	}
}