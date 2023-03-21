#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int a, b, c, d, n, s = 0, e, f, r;
		for (cin >> a >> b >> c >> d >> n; n--;) {
			cin >> e >> f >> r;
			int d1 = (e - a) * (e - a) + (f - b) * (f - b);
			int d2 = (e - c) * (e - c) + (f - d) * (f - d);
			bool a = d1 < r* r, b = d2 < r* r;
			s += (int)(a ^ b);
		}
		cout << s << '\n';
	}

}