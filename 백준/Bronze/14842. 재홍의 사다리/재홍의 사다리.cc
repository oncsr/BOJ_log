#include <iostream>
using namespace std;

int main() {
	double W, H, s = 0;
	int N;
	cin >> W >> H >> N;
	for (int i = 1; i < (N + 1) / 2; i++) {
		s += H * (1.0 - (double)i * 2 / N);
	}
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << s * 2;
}