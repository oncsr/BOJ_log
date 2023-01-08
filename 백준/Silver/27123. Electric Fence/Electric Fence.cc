#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int n, m, p, d;
	cin >> n >> m >> p;
	int s1 = gcd(n, m), s2;
	if (n == p)	s2 = m;
	else	s2 = gcd(m, abs(n - p));
	int s = (double)p * m / 2 - (s1 + s2 + p) / 2. + 1;
	cout << s;
}