#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, n;
	cin >> N;
	cout.setf(ios::fixed);
	cout.precision(3);
	for (int i = 1; i <= N; i++) {
		cout << "Scenario #" << i << ":\n";
		double R;
		cin >> R >> n;
		cout << R * sin(M_PI / n) / (1 + sin(M_PI / n)) << "\n\n";
	}
	cout.unsetf(ios::fixed);
}