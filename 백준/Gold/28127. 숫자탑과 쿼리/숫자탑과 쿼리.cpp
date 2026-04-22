#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int Q;
	for (cin >> Q; Q--;) {
		ll a, d, x;
		cin >> a >> d >> x;
		ll s = 1, e = 1000000, m = (s + e) >> 1;
		while (s <= e) {
			if (x > m * a + m * (m - 1) / 2 * d) {
				if (s == e) {
					m++;
					break;
				}
				s = m + 1;
			}
			else {
				if (s == e)	break;
				e = m;
			}
			m = (s + e) >> 1;
		}
		cout << m << ' ' << x - ((m - 1) * a + (m - 1) * (m - 2) / 2 * d) << '\n';
	}
}