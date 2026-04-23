#include <iostream>
using namespace std;

int main() {
	int T, x, y, a, b, n, c, d, r, s;
	for (cin >> T; T--;) {
		cin >> x >> y >> a >> b;
		s = 0;
		for (cin >> n; n--;) {
			cin >> c >> d >> r;
			int r1 = (c - x) * (c - x) + (d - y) * (d - y);
			int r2 = (c - a) * (c - a) + (d - b) * (d - b);
			if ((r1 < r * r && r2 > r * r) || (r1 > r * r && r2 < r * r))	s++;
		}
		cout << s << '\n';
	}
}