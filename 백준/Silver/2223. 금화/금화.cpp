#include <iostream>
using namespace std;

int main() {
	long long t, x, m, s = 0, a, b, mn = 1000001;
	cin >> t >> x >> m;
	for (; m--;) {
		cin >> a >> b;
		mn = min(mn, (a - 1) / b);
	}
	if (!mn)	cout << 0;
	else {
		if (t < mn) {
			cout << t * x;
		}
		else {
			s += mn * x;
			t -= mn;
			s += t / 2 * x;
			cout << s;
		}
	}
}