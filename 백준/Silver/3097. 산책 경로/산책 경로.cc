#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a = 0, b = 0;
	double arr[30][2]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		a += arr[i][0], b += arr[i][1];
	}
	cout << a << ' ' << b << '\n';
	double mn;
	for (int i = 0; i < n; i++) {
		double t = sqrt((a - arr[i][0]) * (a - arr[i][0]) + (b - arr[i][1]) * (b - arr[i][1]));
		if (!i)	mn = t;
		else	mn = min(mn, t);
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << mn;
	cout.unsetf(ios::fixed);
}