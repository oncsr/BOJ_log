#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int t;
	for (cin >> t; t--;) {
		double a;
		cin >> a;
		a = (a / 100 * 80);
		cout << '$' << a << '\n';
	}
	cout.unsetf(ios::fixed);
}