#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a[100]{};
	int n, m, s = -1, l = -1, x = -1, y = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#') {
				if (x == -1 && y == -1)	x = i, y = j;
				l = j;
				if (s == -1)	s = j;
			}
		}
	}
	int g = l - s;
	if (a[x][y + g / 2] == '.')	cout << "UP";
	if (a[x + g / 2][y] == '.')	cout << "LEFT";
	if (a[x + g / 2][y + g] == '.')	cout << "RIGHT";
	if (a[x + g][y + g / 2] == '.')	cout << "DOWN";
}