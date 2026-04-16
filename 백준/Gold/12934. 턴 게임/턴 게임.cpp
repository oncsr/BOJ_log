#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll x, y;
	cin >> x >> y;
	ll N = -1;
	for (ll i = 1; i <= 2000000; i++) {
		if (i * (i + 1) / 2 == x + y) {
			N = i;
			break;
		}
	}
	if ((!x && !y) || N == -1)	return cout << -1, 0;

	ll ans = 0;
	while (x) {
		if (N <= x) {
			ans++;
			x -= N;
		}
		N--;
	}
	cout << ans;

}