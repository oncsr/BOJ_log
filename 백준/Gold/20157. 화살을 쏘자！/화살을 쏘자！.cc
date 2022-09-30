#include <iostream>
#include <map>
using namespace std;
int gcd(int a, int b) {
	if (b > a)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x, y, m = 0, p, q;
	map<pair<int, int>, int> M;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (y == 0) {
			if (x > 0)	p = 1;
			else	p = -1;
			q = 0;
		}
		else if (x == 0) {
			if (y > 0)	q = 1;
			else	q = -1;
			p = 0;
		}
		else {
			int c = gcd(abs(x), abs(y));
			p = x / c, q = y / c;
		}
		/*
		if (!M[{p, q}])	M[{p, q}] = 1;
		else	M[{p, q}]++;
		*/
		m = max(m, ++M[{p, q}]);
	}
	cout << m;
}