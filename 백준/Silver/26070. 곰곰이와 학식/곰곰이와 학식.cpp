#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, x, y, z, s = 0;
	cin >> a >> b >> c >> x >> y >> z;
	ll g = min(a, x);
	a -= g, x -= g;
	s += g;
	g = min(b, y);
	b -= g, y -= g;
	s += g;
	g = min(c, z);
	c -= g, z -= g;
	s += g;
	if (a > 0) {
		// x = 0
		if (b > 0) {
			// y = 0
			if (z > 0) {
				// c = 0
				x = z / 3;
				g = min(a, x);
				a -= g, x -= g;
				s += g;
				if (x > 0) {
					y = x / 3;
					g = min(b, y);
					s += g;
				}
			}
		}
		else {
			// b = 0
			if (c > 0) {
				z = y / 3;
				g = min(c, z);
				c -= g, z -= g;
				s += g;
				if (z > 0) {
					x = z / 3;
					g = min(a, x);
					s += g;
				}
			}
			else {
				// c = 0
				z += y / 3;
				x = z / 3;
				g = min(a, x);
				s += g;
			}
		}
	}
	else {
		// a = 0
		if (b > 0) {
			// y = 0
			if (c > 0) {
				// z = 0
				y = x / 3;
				g = min(b, y);
				b -= g, y -= g;
				s += g;
				if (y > 0) {
					z = y / 3;
					g = min(c, z);
					s += g;
				}
			}
			else {
				// c = 0
				x += z / 3;
				y = x / 3;
				g = min(b, y);
				s += g;
			}
		}
		else {
			// b = 0
			if (c > 0) {
				// z = 0
				y += x / 3;
				z = y / 3;
				g = min(c, z);
				s += g;
			}
		}
	}
	cout << s;
}