#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;	cin >> x >> y;
		int k = y - x;
		int z = sqrt(k);
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