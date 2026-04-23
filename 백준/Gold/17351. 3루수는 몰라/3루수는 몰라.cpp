#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	char map[501][501]{};
	int n, mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= n; j++)	map[i][j] = temp[j - 1];
	}
	int d[501][501]{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 'M') {
				if (d[i - 1][j] % 4 == 1)	d[i][j] = max(d[i][j], d[i - 1][j]);
				else	d[i][j] = max(d[i][j], d[i - 1][j] / 4 * 4 + 1);
				if (d[i][j - 1] % 4 == 1)	d[i][j] = max(d[i][j], d[i][j - 1]);
				else	d[i][j] = max(d[i][j], d[i][j - 1] / 4 * 4 + 1);
			}
			if (map[i][j] == 'O') {
				if (d[i - 1][j] % 4 == 1)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j] / 4 * 4);
				if (d[i][j - 1] % 4 == 1)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1] / 4 * 4);
			}
			if (map[i][j] == 'L') {
				if (d[i - 1][j] % 4 == 2)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j] / 4 * 4);
				if (d[i][j - 1] % 4 == 2)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1] / 4 * 4);
			}
			if (map[i][j] == 'A') {
				if (d[i - 1][j] % 4 == 3)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j] / 4 * 4);
				if (d[i][j - 1] % 4 == 3)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1] / 4 * 4);
			}
			d[i][j] = max(d[i][j], d[i][j - 1] / 4 * 4);
			d[i][j] = max(d[i][j], d[i - 1][j] / 4 * 4);
			mx = max(d[i][j], mx);
		}
	}
	cout << mx / 4;
}