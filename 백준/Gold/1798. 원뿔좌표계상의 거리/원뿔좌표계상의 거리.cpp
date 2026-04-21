#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ld r, h, d1, a1, d2, a2, b;
	while (cin >> r >> h >> d1 >> a1 >> d2 >> a2) {
		b = min(abs(a1 - a2), 360 - abs(a1 - a2));
		ld x = M_PI * 2 * r / sqrt(r * r + h * h);
		ld t = b * x / 360.;
		ld A = d2 - d1 * cos(t), B = d1 * sin(t);
		cout.precision(2);
		cout << fixed << sqrt(A * A + B * B) << '\n';
	}

}