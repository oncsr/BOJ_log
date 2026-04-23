#include <iostream>
using namespace std;

int main() {
	int n, a;
	double p = 0, q = 0;
	for (cin >> n; n--;) {
		cin >> a;
		if (a % 3 == 0)	q++;
		if (a % 3 == 1)	p++;
		if (a % 3 == 2)	p--, q--;
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << p << ' ' << q;
	cout.unsetf(ios::fixed);
}