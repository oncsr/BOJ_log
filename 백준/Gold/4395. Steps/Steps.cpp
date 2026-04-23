#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, n, k, z;
	for (cin >> n; n--;) {
		cin >> x >> y;
		k = y - x, z = sqrt(k);
		if (x == y)	cout << 0 << '\n';
		else {
			if (k - z * z == 0)
				cout << z * 2 - 1 << '\n';
			else
			{
				if (k > z * z + z)
					cout << z * 2 + 1 << '\n';
				else
					cout << z * 2 << '\n';
			}
		}
	}
}