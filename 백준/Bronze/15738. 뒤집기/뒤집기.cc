#include <iostream>
using namespace std;

int main() {
	int n, k, m, a, g, c;
	cin >> n >> k >> m;
	c = k;
	for (g = n; g--;)cin >> a;
	while (m--) {
		cin >> a;
		if (a > 0 && c <= a)	c = (a + 1) - c;
		else if (a < 0 && c >= n + a + 1)	c = (2 * n + a + 1) - c;
	}
	cout << c;
}