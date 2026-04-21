#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	for (cin >> t; t--;) {
		int n, m;
		cin >> n >> m;
		n -= m;
		if (m & 1)	m--;
		else	m -= 2;
		if (!m) {
			cout << 1 << '\n';
			continue;
		}
		bool sat = 1;
		int g = pow(2, (int)log2(m));
		int one = 0;
		while (g) {
			if (m & g) {
				if (!one)	one = g;
			}
			else {
				if (one) {
					sat &= (n % one < g);
					one = 0;
				}
			}
			g >>= 1;
		}
		cout << (int)sat << '\n';
	}

}