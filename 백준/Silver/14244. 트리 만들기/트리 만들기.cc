#include <iostream>
using namespace std;

int main() {
	int n, m, p;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		if (i < n - m + 1) {
			cout << i << ' ' << i + 1 << '\n';
			p = i;
		}
		else	cout << p << ' ' << i + 1 << '\n';
	}
}