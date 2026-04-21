#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ll d, x, y;
		cin >> d >> x >> y;
		
		ll total = x * x + y * y;
		if (x == 0 && y == 0) { cout << 0 << '\n'; continue; }
		if (total < d) { cout << 2 << '\n'; continue; }
		if (total % d) {
			ll i = 0;
			for (; i * i <= total / d; i++);
			cout << i << '\n';
		}
		else {
			total /= d;
			bool yes = 0;
			ll i = 0;
			for (; i * i <= total; i++) {
				if (i * i == total)	yes = 1;
			}
			i--;

			if (yes)	cout << i << '\n';
			else	cout << i + 1 << '\n';
		}
	}

}