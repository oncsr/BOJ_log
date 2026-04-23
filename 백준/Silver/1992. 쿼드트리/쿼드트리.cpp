#include <iostream>
using namespace std;

int m[65][65]{}, n;

void solve(int x, int y, int xx, int yy) {
	if (x == xx) {
		cout << m[x][y];
		return;
	}
	int one = 0, zero = 0;
	for (int i = x; i <= xx; i++) {
		for (int j = y; j <= yy; j++) {
			if (m[i][j])	one++;
			else	zero++;
		}
	}
	int sz = (xx - x + 1) * (yy - y + 1);
	if (one == sz) {
		cout << 1;
		return;
	}
	else if (zero == sz) {
		cout << 0;
		return;
	}
	else {
		cout << '(';
		int mx = (x + xx) / 2;
		int my = (y + yy) / 2;
		solve(x, y, mx, my);
		solve(x, my + 1, mx, yy);
		solve(mx + 1, y, xx, my);
		solve(mx + 1, my + 1, xx, yy);
		cout << ')';
	}
}

int main() {
	cin >> n;
	char a;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a;
			m[i][j] = a - '0';
		}
	int one = 0, zero = 0;
	solve(1, 1, n, n);
}