#include <iostream>
using namespace std;

int main() {
	int n, p, a;
	cin >> n >> p;
	if (n >= 20)	a = min(p - 2000, p / 100 * 75);
	else if (n >= 15)	a = min(p - 2000, p / 100 * 90);
	else if (n >= 10)	a = min(p - 500, p / 100 * 90);
	else if (n >= 5)	a = p - 500;
	else	a = p;
	cout << (a > 0 ? a : 0);
}