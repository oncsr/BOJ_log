#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F(ll n) {
	if (n < 0)	return 0;
	ll res = n / 10 + 1, d = 100;
	while (d <= n) {
		res += max(0LL, (n / d - 1) * (d / 10) + min(d / 10 - 1, n % d) + 1);
		d *= 10;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m;
	for (cin >> n >> m; n >= 0; cin >> n >> m)	cout << F(m) - F(n - 1) << '\n';

}