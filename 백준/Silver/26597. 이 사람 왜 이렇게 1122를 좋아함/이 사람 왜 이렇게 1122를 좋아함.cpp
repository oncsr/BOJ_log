#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int q;
	cin >> q;
	ll up, down;
	up = 1000000000000000001;
	down = -1000000000000000001;
	bool paradox = false, first = true;
	ll ans = -1;
	for (int i = 1; i <= q; i++) {
		ll a;
		char o;
		cin >> a >> o;
		if (!paradox) {
			if (o == '^') {
				if (a >= up) {
					paradox = true;
					ans = i;
				}
				else {
					down = max(down, a + 1);
				}
			}
			else {
				if (a <= down) {
					paradox = true;
					ans = i;
				}
				else {
					up = min(up, a - 1);
				}
			}
			if (down == 1000000000000000000 && first) {
				ans = i;
				first = false;
			}
			if (up == -1000000000000000000 && first) {
				ans = i;
				first = false;
			}
			if (up == down && first) {
				if (up > 1000000000000000000 || down < -1000000000000000000) {
					ans = i;
					paradox = true;
				}
				else {
					ans = i;
					first = false;
				}
			}
		}
	}
	if (paradox)	cout << "Paradox!\n" << ans;
	else {
		if (!first)	cout << "I got it!\n" << ans;
		else	cout << "Hmm...";
	}
}