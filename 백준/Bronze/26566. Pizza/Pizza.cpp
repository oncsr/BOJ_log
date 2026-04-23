#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	for (cin >> N; N--;) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		double t1 = a / b;
		double t2 = c * c * M_PI / d;
		cout << (t1 > t2 ? "Slice of pizza\n" : "Whole pizza\n");
	}
}