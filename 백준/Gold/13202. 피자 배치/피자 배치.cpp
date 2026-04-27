#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(double a, double b) { return a > b; }

int main() {
	int T;
	cout.setf(ios::fixed);
	cout.precision(6);
	for (cin >> T; T--;) {
		double a, b, S[303]{};
		int k, id = 0;
		cin >> a >> b >> k;
		double r = ((a + b) + sqrt(a * a + b * b)) / 2;
		if (r >= min(a, b))	r = ((a + b) - sqrt(a * a + b * b)) / 2;
		S[id++] = r * r * M_PI;
		double r2 = r, r3 = r;
		double bot = a - r;
		double d = sqrt(bot * bot + r * r) - r;
		r = r * d / (2 * r + d);
		S[id++] = r * r * M_PI;
		for (int i = 0; i < k - 1; i++) {
			bot = sqrt(d * d - 2 * d * r);
			d = sqrt(bot * bot + r * r) - r;
			r = r * d / (2 * r + d);
			S[id++] = r * r * M_PI;
		}
		bot = b - r2;
		d = sqrt(bot * bot + r2 * r2) - r2;
		r2 = r2 * d / (2 * r2 + d);
		S[id++] = r2 * r2 * M_PI;
		for (int i = 0; i < k - 1; i++) {
			bot = sqrt(d * d - 2 * d * r2);
			d = sqrt(bot * bot + r2 * r2) - r2;
			r2 = r2 * d / (2 * r2 + d);
			S[id++] = r2 * r2 * M_PI;
		}
		r3 = (3 - 2 * sqrt(2)) * r3;
		S[id++] = r3 * r3 * M_PI;
		for (int i = 0; i < k - 1; i++) {
			r3 = (3 - 2 * sqrt(2)) * r3;
			S[id++] = r3 * r3 * M_PI;
		}
		sort(S, S + id, cmp);
		cout << S[k - 1] << '\n';
	}
	cout.unsetf(ios::fixed);
}