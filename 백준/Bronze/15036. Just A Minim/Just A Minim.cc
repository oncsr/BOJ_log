#include <iostream>
#include <map>
using namespace std;

int main() {
	double s = 0;
	int n, a;
	for (cin >> n; n--;) {
		cin >> a;
		if (a == 0)	s += 2;
		else {
			s += (1 / (double)a);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << s;
	cout.unsetf(ios::fixed);
}