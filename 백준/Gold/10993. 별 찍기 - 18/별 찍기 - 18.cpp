#include <bits/stdc++.h>
using namespace std;

int ans[1024][2048]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	int x = (n & 1) ? 1 : (1 << n) - 1;
	for (int i = n; i > 0; i--) {
		int y = (1 << n) - 1, d = 0, g = (i & 1) ? 1 : -1;
		for (; x + d >= 1 && y - d >= 1;) {
			ans[x + d][y - d] = ans[x + d][y + d] = 1;
			if (ans[x + d][y - abs(d) - 1])	break;
			d += g;
			if (x + d < 1 || y - d < 1) { d -= g; break; }
		}
		for (int j = y - abs(d); j < y + abs(d); j++)	ans[x + d][j] = 1;
		x = x + d - g;
	}
	for (int i = 1; i <= (1 << n) - 1; i++) {
		for (int j = 1; j <= ((n & 1) ? (1 << n) - 1 + i : 2 * ((1 << n) - 1) - i); j++)	cout << (ans[i][j] ? '*' : ' ');
		cout << '\n';
	}
	
}