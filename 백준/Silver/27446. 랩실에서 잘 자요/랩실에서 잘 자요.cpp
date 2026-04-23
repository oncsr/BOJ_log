#include <iostream>
using namespace std;

int main() {
	int exi[101]{}, n, m, a, t = 0, s = 0;
	for (cin >> n >> m; m--;) {
		cin >> a;
		exi[a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!exi[i]) {
			if (!t) {
				s = 7;
			}
			else {
				s += min(2 * (i - t), 7);
			}
			t = i;
		}
	}
	cout << s;
}