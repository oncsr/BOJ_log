#include <iostream>
using namespace std;

int main() {
	int n, a = 1, d = 2;
	cin >> n;
	cout << n * (n - 1) / 2 << '\n';
	for (int i = 0; i < n; i++) {
		cout << a;
		if (i != n - 1)	cout << ' ';
		a *= d;
	}
	cout << '\n' << n - 1 << '\n';
	a = 1;
	for (int i = 0; i < n; i++) {
		cout << a++;
		if (i != n - 1)	cout << ' ';
	}
}