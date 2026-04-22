#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		ll n;
		cin >> n;
		if (!(n & 1))	n--;
		ll G = 0, c = 1;
		while (n > 0) {
			ll a = n / 3, b = n;
			if (n % 3) {
				if (!(a & 1))	a--;
			}
			ll sa = ((a + 1) >> 1) * ((a + 1) >> 1);
			ll sb = ((b + 1) >> 1) * ((b + 1) >> 1);
			sa *= c, sb *= c;
			G += sb - sa;
			c *= 2;
			n /= 3;
		}
		cout << G << '\n';
	}
}