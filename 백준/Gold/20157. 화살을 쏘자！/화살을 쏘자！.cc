#include <iostream>
#include <map>
using namespace std;
int gcd(int a, int b) {
	if (b > a)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}
int main() {
	int n, x, y, m = 0;
	map<pair<int, int>, int> M;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (y == 0) {
			if (x > 0) {
				if (!M[{0, 1}])	M[{0, 1}] = 1;
				else	M[{0, 1}]++;
				m = max(M[{0, 1}], m);
			}
			else {
				if (!M[{0, -1}])	M[{0, -1}] = 1;
				else	M[{0, -1}]++;
				m = max(M[{0, -1}], m);
			}
		}
		else if (x == 0) {
			if (y > 0) {
				if (!M[{1, 0}])	M[{1, 0}] = 1;
				else	M[{1, 0}]++;
				m = max(M[{1, 0}], m);
			}
			else {
				if (!M[{-1, 0}])	M[{-1, 0}] = 1;
				else	M[{-1, 0}]++;
				m = max(M[{-1, 0}], m);
			}
		}
		else {
			int c = gcd(abs(x), abs(y));
			if (!M[{x / c, y / c}])	M[{x / c, y / c}] = 1;
			else	M[{x / c, y / c}]++;
			m = max(m, M[{x / c, y / c}]);
		}
	}
	cout << m;
}