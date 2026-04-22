#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a = 1, d = 0, r = 1;
	int Q;
	for (cin >> Q; Q--;) {
		int o;
		cin >> o;
		if (o == 3)	cout << a * r + d << '\n';
		else {
			ll g;
			cin >> g;
			if (o == 0)	d += g;
			if (o == 1)	r *= g, d *= g;
			if (o == 2)	a += g;
		}
	}
}