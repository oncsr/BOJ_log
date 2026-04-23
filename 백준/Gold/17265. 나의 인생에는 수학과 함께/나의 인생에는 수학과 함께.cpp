#include <iostream>
using namespace std;

char map[5][5]{};
int mx = -15626, mn = 15626, n;

void dfs(int x, int y, int v, char o) {
	if (o == 'o') {
		if (x + 1 < n)	dfs(x + 1, y, v, map[x][y]);
		if (y + 1 < n)	dfs(x, y + 1, v, map[x][y]);
	}
	else {
		int t = map[x][y] - '0';
		if (x || y) {
			if (o == '+')	v += t;
			if (o == '-')	v -= t;
			if (o == '*')	v *= t;
			if (x == n - 1 && y == n - 1) {
				mx = max(mx, v);
				mn = min(mn, v);
				return;
			}
		}
		else	v = t;
		if (x + 1 < n)	dfs(x + 1, y, v, 'o');
		if (y + 1 < n)	dfs(x, y + 1, v, 'o');
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	dfs(0, 0, 0, '+');
	cout << mx << ' ' << mn;
}