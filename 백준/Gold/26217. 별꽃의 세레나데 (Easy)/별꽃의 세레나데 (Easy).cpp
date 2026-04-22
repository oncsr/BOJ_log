#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(6);
	int n;
	double s = 0.;
	cin >> n;
	for (int i = 1; i <= n; i++)	s += ((double)n / i);
	cout << s;
	cout.unsetf(ios::fixed);
}