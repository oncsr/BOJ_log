#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, k, s = 0;
	cin >> n >> k;
	ll start1_y = k / 2 + 1;
	ll a = start1_y * 2 - 1;
	if (start1_y <= n) {
		ll g1 = n - start1_y + 1;
		s += (a * g1 + g1 * (g1 - 1));
		if (a + (g1 - 1) * 2 > n * 2 - 1) {
			ll temp = a + (g1 - 1) * 2 - (n * 2 - 1);
			temp /= 2;
			s -= (temp * (temp + 1));
		}
	}
	if (k % 2)	start1_y--;
	else	start1_y -= 2;
	if (start1_y >= -n) {
		ll g1 = start1_y + n + 1;
		s += (a * g1 + g1 * (g1 - 1));
		if (a + (g1 - 1) * 2 > n * 2 + 1) {
			ll temp = a + (g1 - 1) * 2 - (n * 2 + 1);
			temp /= 2;
			s -= (temp * (temp + 1));
		}
	}
	cout << min((n * 2 + 1) * (n * 2 + 1), s);
}