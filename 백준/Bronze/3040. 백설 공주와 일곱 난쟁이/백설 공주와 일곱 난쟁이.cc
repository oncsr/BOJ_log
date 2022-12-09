#include <iostream>
using namespace std;

int main() {
	int s = 0, a[9]{}, b, c, br = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (s - a[i] - a[j] == 100) {
				b = i, c = j, br = 1;
				break;
			}
		}
		if (br)	break;
	}
	for (int i = 0; i < 9; i++) {
		if (i == b || i == c)	continue;
		cout << a[i] << '\n';
	}
}