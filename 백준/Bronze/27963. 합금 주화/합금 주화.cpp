#include <iostream>
using namespace std;

int main() {
	double d1, d2, x;
	cin >> d1 >> d2 >> x;
	if (d1 < d2)	x = 100 - x;
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << 100 * d1 * d2 / (x * (d2 + 100 * d1 / x - d1));
	cout.unsetf(ios::fixed);
}