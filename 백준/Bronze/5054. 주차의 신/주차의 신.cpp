#include <iostream>
using namespace std;

int main() {
	int t;
	for (cin >> t; t--;) {
		int n, x = 0, m = 100, a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			m = min(a, m);
			x = max(a, x);
		}
		cout << (x - m) * 2 << '\n';
	}
}