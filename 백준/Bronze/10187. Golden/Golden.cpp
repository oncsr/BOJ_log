#include <iostream>
using namespace std;

int main() {
	int t;
	for (cin >> t; t--;) {
		double a, b, c;
		cin >> a >> b;
		c = b * 1.61803399;
		if (c / a >= 0.99 && c / a <= 1.01)	cout << "golden\n";
		else	cout << "not\n";
	}
}