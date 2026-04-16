#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll n, h;
	cin >> n >> h;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a[3]{};
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		int x = 0;
		while (x < 3) {
			if (a[x] > h) { x--; break; }
			x++;
		}
		if (x == 3)	x--;
		if (x < 0)	return cout << "impossible", 0;
		for (int j = 0; j < 3; j++) {
			if (j == x)	continue;
			ans += a[j];
			break;
		}
	}
	cout << ans;

}