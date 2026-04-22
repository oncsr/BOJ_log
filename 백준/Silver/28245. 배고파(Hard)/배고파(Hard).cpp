#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;
	for (cin >> n; n--;) {
		cin >> m;
		if (m <= 2)	cout << "0 0\n";
		else {
			ll temp = m;
			int prev = -1, prev2 = -1, i = 0, f = 0;
			while (m) {
				if (m % 2 == 1) {
					prev2 = prev;
					prev = i;
				}
				else	f++;
				i++;
				m >>= 1;
			}
			if (prev2 == -1) {
				cout << prev - 1 << ' ' << prev - 1 << '\n';
			}
			else {
				ll a1 = (1LL << prev2) + (1LL << prev);
				ll a2 = (1LL << (prev2 + 1)) + (1LL << prev);
				if (abs(a2 - temp) < abs(a1 - temp))	cout << prev2 + 1 << ' ' << prev << '\n';
				else	cout << prev2 << ' ' << prev << '\n';
			}
		}
	}
}