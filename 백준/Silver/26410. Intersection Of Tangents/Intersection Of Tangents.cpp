#include <iostream>
using namespace std;

int main() {
	int n, a, b, c = 1000000001, d = 1000000001;
	for (cin >> n; n--;) {
		cin >> a >> b;
		c = min(c, a), d = min(b, d);
	}
	cout << c << ' ' << d;
}