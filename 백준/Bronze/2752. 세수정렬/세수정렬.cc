#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		if (b > c)
			cout << c << ' ' << b << ' ' << a << '\n';
		else if (a > c)
			cout << b << ' ' << c << ' ' << a << '\n';
		else
			cout << b << ' ' << a << ' ' << c << '\n';
	}
	else {
		if (a > c)
			cout << c << ' ' << a << ' ' << b << '\n';
		else if (b > c)
			cout << a << ' ' << c << ' ' << b << '\n';
		else
			cout << a << ' ' << b << ' ' << c << '\n';
	}
}