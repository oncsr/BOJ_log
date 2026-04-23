#include <iostream>
using namespace std;

int main() {
	int n, a = 1, b = 1, k = 1;	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (a == 1)	a = ++k, b = 1;
		else	a--, b++;
	}
	cout << a << ' ' << b;
}