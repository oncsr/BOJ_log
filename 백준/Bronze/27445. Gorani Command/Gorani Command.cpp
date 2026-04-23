#include <iostream>
using namespace std;

int main() {
	int n, m, a = -1, b = -1, c, t;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> c;
		if (i != 1)	{
			if (c > t && a < 0)	a = i - 1;
		}
		t = c;
	}
	for (int i = 1; i <= m; i++) {
		cin >> c;
		if (i == 1) {
			if (a < 0) {
				if (c > t)	a = n - 1;
				else	a = n;
			}
		}
		else {
			if (c > t && b < 0)	b = i - 1;
		}
		t = c;
	}
	if (b < 0)	b = m;
	cout << a << ' ' << b;
}