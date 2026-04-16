#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		ui n, m, x;
		cin >> n >> m >> x;
		if (m <= 3)	cout << 0 << '\n';
		else {
			if (x + 2 * n >= 2 * m)	cout << 0 << '\n';
			else if (x + 2 * n > m) {
				if (x + n <= m)	cout << 0 << '\n';
				else {
					if (x + 2 * n == 2 * m - 1)	cout << (x + n - 1) % m << '\n';
					else	cout << (x + n) % m << '\n';
				}
			}
			else if (x + 2 * n == m)	cout << 0 << '\n';
			else if (x + 2 * n == m - 1)	cout << x + n - 1 << '\n';
			else	cout << x + n << '\n';
		}
	}

}