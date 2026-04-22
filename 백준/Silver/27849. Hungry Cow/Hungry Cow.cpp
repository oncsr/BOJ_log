#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, t, h = 0, s = 0, d = 1;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (!i) {
			d = a, h = b;
			continue;
		}
		s += min(a - d, h);
		h -= min(a - d, h);
		d = a, h += b;
	}
	s += min(t + 1 - d, h);
	cout << s;
}