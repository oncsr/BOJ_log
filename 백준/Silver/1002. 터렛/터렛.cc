#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		double a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		double G = sqrt((a - d) * (a - d) + (b - e) * (b - e));
		if (a == d && b == e) {
			if (c != f)	cout << 0 << '\n';
			else	cout << -1 << '\n';
		}
		else {
			if (G == c + f)	cout << 1 << '\n';
			else if (G > c + f)	cout << 0 << '\n';
			else {
				if (c > f) {
					if (G + f > c)	cout << 2 << '\n';
					else if (G + f == c)	cout << 1 << '\n';
					else	cout << 0 << '\n';
				}
				else {
					if (G + c > f)	cout << 2 << '\n';
					else if (G + c == f)	cout << 1 << '\n';
					else	cout << 0 << '\n';
				}
			}
		}
	}

}