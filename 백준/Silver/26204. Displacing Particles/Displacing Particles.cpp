#include <iostream>
using namespace std;

int main() {
	long long n, x, y, s = 1, r, p = 0, q = 0, g;
	cin >> n >> x >> y;
	n--;
	while (n--)	s *= 2;
	g = r = s;
	while (s != x) {
		g /= 2;
		if (s > x)	s -= g;
		else	s += g;
		p++;
	}
	g = r;
	while (r != x) {
		g /= 2;
		if (r > x)	r -= g;
		else	r += g;
		q++;
	}
	cout << max(p, q);
}