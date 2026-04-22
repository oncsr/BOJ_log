#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> V;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		ll g = 1, r = 0, s = 1;
		while (a >= g)	g *= 10;
		g /= 10;
		while (a > 0) {
			ll t = a / g;
			r += s * t;
			a -= t * g;
			g /= 10;
			s *= 10;
		}
		V.push_back(r);
	}
	sort(V.begin(), V.end());
	for (ll i : V)	cout << i << '\n';
}