#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double s = 0, e = min(a, b), h = (s + e) / 2;
	double beta = sqrt(b * b - h * h) * sqrt(a * a - h * h) / (sqrt(b * b - h * h) + sqrt(a * a - h * h));
	while (abs(beta - c) > 0.00001) {
		if (beta > c)	s = h;
		else if (beta < c)	e = h;
		h = (s + e) / 2;
		beta = sqrt(b * b - h * h) * sqrt(a * a - h * h) / (sqrt(b * b - h * h) + sqrt(a * a - h * h));
	}
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << h;
}