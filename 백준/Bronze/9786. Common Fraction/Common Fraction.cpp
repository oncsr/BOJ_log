#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int n, a, b;
	for (cin >> n; n--;) {
		cin >> a >> b;
		int g = gcd(a, b);
		cout << a / g << ' ' << b / g << '\n';
	}
}