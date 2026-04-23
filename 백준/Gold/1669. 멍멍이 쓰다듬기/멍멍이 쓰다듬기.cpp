#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y;	cin >> x >> y;
	int k = y - x;
	int z = sqrt(k);
	if (x == y)	cout << 0;
	else {
		if (k - z * z == 0)
			cout << z * 2 - 1;
		else
		{
			if (k > z * z + z)
				cout << z * 2 + 1;
			else
				cout << z * 2;
		}
	}
}