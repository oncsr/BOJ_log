#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll x;
	cin >> x;
	ll s = 1, e = 2e9, m = (s + e) >> 1;
	while (s < e) {
		if (x <= m * (m + 1) / 2)	e = m;
		else	s = m + 1;
		m = (s + e) >> 1;
	}
	x = x - m * (m - 1) / 2;
	if (m & 1)	cout << m - x + 1 << '/' << x;
	else	cout << x << '/' << m - x + 1;

}