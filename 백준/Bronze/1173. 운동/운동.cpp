#include <iostream>
using namespace std;

int main() {
	int n, m, M, t, r, x, s = 0, g = 0;
	cin >> n >> m >> M >> t >> r;
	if (m + t > M)	cout << -1;
	else {
		x = m;
		while (g < n) {
			if (x + t > M)	x = max(x - r, m);
			else	x += t, g++;
			s++;
		}
		cout << s;
	}
}