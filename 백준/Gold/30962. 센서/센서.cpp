#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int Q;
	for (cin >> Q; Q--;) {
		ll x, y, xx, yy, w;
		cin >> x >> y >> xx >> yy >> w;
		if (y * xx < x * yy)	swap(x, y), swap(xx, yy);
		int ans = 0;
		for (ll i = 1; i * i < w; i++) {
			ll j = sqrt(w - i * i);
			vector<ll> chk = { max(1LL,j - 2), max(1LL,j - 1), j, j + 1, j + 2 };
			bool poss = 0;
			for (ll k : chk) {
				if (i * i + k * k == w) {
					j = k;
					poss = 1;
					break;
				}
			}
			if (!poss)	continue;
			if (yy * i <= j * xx && j * x <= i * y)	ans++;
		}
		cout << ans << '\n';
	}

}