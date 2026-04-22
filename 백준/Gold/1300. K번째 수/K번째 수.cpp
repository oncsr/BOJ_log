#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k;
	cin >> n >> k;
	ll a = 1, b = n * n, m = (a + b) >> 1;
	
	while (a <= b) {
		ll c = 0, d = 0;
		for (int i = 1; i <= n; i++) {
			c += min(i * n, (m - 1)) / i;
			d += min(i * n, m) / i;
		}
		if (c < k && k <= d) {
			cout << m;
			return 0;
		}
		if (k > d)	a = m + 1;
		else	b = m;
		m = (a + b) >> 1;
	}

}