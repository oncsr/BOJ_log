#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int P, a = 0, b = 0, c = 0, d = 0;
	for (cin >> P; P--;) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1)	d++;
		else {
			if (y <= 2)	a++;
			else if (y == 3)	b++;
			else	c++;
		}
	}
	cout << a << '\n' << b << '\n' << c << '\n' << d;

}