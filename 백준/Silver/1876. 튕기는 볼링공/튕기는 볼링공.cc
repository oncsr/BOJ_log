#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	for (cin >> N; N--;) {
		long double T, X;
		cin >> T >> X;
		T *= 100.0;
		long double t = tan(X * M_PI / 180.0);
		int cross = 0;
		long double Q = 0;
		if (-T * t < -42.5) {
			Q = -42.5;
			while (-T * t < Q) {
				cross++;
				Q -= 85.0;
			}
		}
		Q = -85.0 * cross;
		if (abs(T * t + Q) / sqrt(t * t + 1.0) < 16.0)	cout << "yes\n";
		else	cout << "no\n";
	}
}