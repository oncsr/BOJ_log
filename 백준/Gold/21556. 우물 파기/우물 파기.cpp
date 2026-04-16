#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)	cin >> i;
	sort(a.begin(), a.end());
	ll s = 1, e = 2e9, m = s + e >> 1, x = (n * (n - 1) / 2 + 1) / 2;
	while (s < e) {
		ll k = 0;
		for (int i = 0; i < a.size(); i++)	k += upper_bound(a.begin() + i + 1, a.end(), m - a[i]) - (a.begin() + i + 1);
		if (x <= k)	e = m;
		else	s = m + 1;
		m = s + e >> 1;
	}
	cout << m;

}