#include <iostream>
using namespace std;
int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
int main() {
	int c, d;
	cin >> c >> d;
	int x = max(c, d);
	int y = min(c, d);
	int tm = y;
	int r = gcd(x, y);
	x /= r;
	y /= r;
	cout << ((x + y) - 1) * (tm / y) << '\n';
}