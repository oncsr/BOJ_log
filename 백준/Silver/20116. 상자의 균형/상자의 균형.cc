#include <iostream>
using namespace std;

int main() {
	int N, c = 1;
	double s = 0, a[200000]{}, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < N - 1; i++) {
		s -= a[i];
		double t = (double)s / (N - (i + 1));
		if (!(t > a[i] - L && t < a[i] + L)) {
			c = 0;
			break;
		}
	}
	cout << (c ? "stable" : "unstable");
}