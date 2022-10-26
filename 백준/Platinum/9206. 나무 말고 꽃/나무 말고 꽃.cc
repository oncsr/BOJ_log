#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double v, a, b, h;
	int n;
	cin >> v >> n;
	double ans = 0;
	int id = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> h;
		double cur = b * b * h * h / 2;
		double part1 = 0, part2 = 0;
		for (double x = 0.00001; x < h; x += 0.00001) {
			double dx = x - 0.000005;
			part1 += 0.00001 * (sqrt(dx) * pow(1.0 / M_E, dx * dx));
		}
		for (double x = 0.00001; x < h; x += 0.00001) {
			double dx = x - 0.000005;
			part2 += 0.00001 * pow(1.0 / (M_E * M_E), dx * dx);
		}
		part1 *= (2 * a * b);
		part2 *= (a * a);
		cur += part1;
		cur += part2;
		cur *= M_PI;

		if (i == 0) {
			ans = cur;
			id = i;
			continue;
		}
		if (abs(cur - v) < abs(ans - v)) {
			ans = cur;
			id = i;
		}
	}
	cout << id << '\n';
}