#include <iostream>
using namespace std;

int map[2188][2188]{};
int a = 0, b = 0, c = 0;

void D(int x, int y, int xx, int yy) {
	int aa = 0, bb = 0, cc = 0;
	if (x == xx) {
		if (map[x][y] == -1)	a++;
		else if (map[x][y])	c++;
		else	b++;
		return;
	}
	for (int i = x; i <= xx; i++) {
		for (int j = y; j <= yy; j++) {
			if (map[i][j] == -1)	aa++;
			else if (map[i][j] == 1)	cc++;
			else	bb++;
		}
	}
	int ch = (xx - x + 1) * (yy - y + 1);
	if (aa == ch) {
		a++;
		return;
	}
	if (bb == ch) {
		b++;
		return;
	}
	if (cc == ch) {
		c++;
		return;
	}
	int mx = (xx - x + 1) / 3;
	int my = (yy - y + 1) / 3;
	D(x, y, x + mx - 1, y + my - 1);
	D(x + mx, y, x + mx + mx - 1, y + my - 1);
	D(x + mx + mx, y, xx, y + my - 1);
	D(x, y + my, x + mx - 1, y + my + my - 1);
	D(x + mx, y + my, x + mx + mx - 1, y + my + my - 1);
	D(x + mx + mx, y + my, xx, y + my + my - 1);
	D(x, y + my + my, x + mx - 1, yy);
	D(x + mx, y + my + my, x + mx + mx - 1, yy);
	D(x + mx + mx, y + my + my, xx, yy);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	D(1, 1, N, N);
	cout << a << '\n' << b << '\n' << c;
}