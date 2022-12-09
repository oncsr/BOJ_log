#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double r1 = sqrt((a - c) * (a - c) + (b - d) * (b - d));
	double r2 = sqrt((c - e) * (c - e) + (d - f) * (d - f));
	double r3 = sqrt((e - a) * (e - a) + (f - b) * (f - b));
	double d1, d2;
	if (a == c)	d1 = 0;
	else if (b == d)	d1 = 2147483647;
	else	d1 = (d - b) / (c - a);
	if (c == e)	d2 = 0;
	else if (d == f)	d2 = 2147483647;
	else	d2 = (f - d) / (e - c);
	if (d1 == d2)	cout << "-1.0";
	else	cout << max(abs(2 * r1 - 2 * r2), max(abs(2 * r1 - 2 * r3), abs(2 * r2 - 2 * r3)));
	cout.unsetf(ios::fixed);
}