#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	int e, f;
	f = b * d;
	a *= d;
	c *= b;
	e = a + c;
	if (e == f) {
		e = 1;
		f = 1;
	}
	else {
		for (int i = 2; i <= f; i++) {
			if (e % i == 0 && f % i == 0) {
				e /= i;
				f /= i;
				i = 1;
			}
		}
	}
	cout << e << ' ' << f << '\n';
}