#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(6);
	int N;
	double a[100000]{}, mx = 0, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < N; i++)	mx = max(mx, (s - a[i]) / 2 + a[i]);
	cout << mx;
	cout.unsetf(ios::fixed);
}