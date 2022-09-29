#include <iostream>
using namespace std;

int main() {
	int n, a[50]{}, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	while (1) {
		int t = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				if (a[i] % 2) {
					a[i]--;
					s++;
				}
				a[i] /= 2;
				t++;
			}
		}
		if (!t)	break;
		s++;
	}
	cout << (s?--s:s);
}