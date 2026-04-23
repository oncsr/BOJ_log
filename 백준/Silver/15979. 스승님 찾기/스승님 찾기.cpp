#include <iostream>
using namespace std;
int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
int main() {
	int a, b;
	cin >> a >> b;
	a = abs(a), b = abs(b);
	if (a < b)	swap(a, b);
	if (a == 0 && b == 0)	cout << 0;
	else if (a == 0)	cout << (b == 1 ? 1 : 2);
	else if (b == 0)	cout << (a == 1 ? 1 : 2);
	else	cout << (gcd(a, b) == 1 ? 1 : 2);
}