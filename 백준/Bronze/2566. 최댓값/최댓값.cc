#include <iostream>
using namespace std;

int main() {
	int a, mx = -1, x, y;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			cin >> a;
			if (a > mx)
				mx = a, x = i, y = j;
		}
	cout << mx << '\n' << x << ' ' << y;
}