#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i)	continue;
		int a = i, b = n / i;
		for (int j = 1; j * j <= n + 2; j++) {
			if ((n + 2) % j)	continue;
			int c = j, d = (n + 2) / j;
			if (a * d - c * b == n + 1) {
				cout << a << ' ' << -c << ' ' << b << ' ' << d;
				return 0;
			}
			if (c * b - a * d == n + 1) {
				cout << a << ' ' << c << ' ' << b << ' ' << -d;
				return 0;
			}
		}
	}
	cout << -1;
}