#include <iostream>
using namespace std;

int main() {
	int n, d[17][17][3]{}, map[17][17]{};
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	d[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == 1 && j == 2)	continue;
			if (map[i][j])	continue;
			d[i][j][0] = (d[i][j - 1][0] + d[i][j - 1][1]);
			d[i][j][2] = (d[i - 1][j][1] + d[i - 1][j][2]);
			if (map[i - 1][j] || map[i][j - 1])	continue;
			d[i][j][1] = (d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2]);
		}
	}
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2];
}