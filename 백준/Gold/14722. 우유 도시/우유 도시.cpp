#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[1001][1001]{}, d[1001][1001]{}, n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				if (d[i - 1][j] % 3 == 0)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j]);
				if (d[i][j - 1] % 3 == 0)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1]);
			}
			if (map[i][j] == 1) {
				if (d[i - 1][j] % 3 == 1)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j]);
				if (d[i][j - 1] % 3 == 1)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1]);
			}
			if (map[i][j] == 2) {
				if (d[i - 1][j] % 3 == 2)	d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else	d[i][j] = max(d[i][j], d[i - 1][j]);
				if (d[i][j - 1] % 3 == 2)	d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else	d[i][j] = max(d[i][j], d[i][j - 1]);
			}
		}
	}
	cout << d[n][n];
}