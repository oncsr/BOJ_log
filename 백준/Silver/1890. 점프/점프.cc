#include <iostream>
using namespace std;

int main() {
	int m[101][101];
	long long d[101][101]{};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> m[i][j];
	d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n)	break;
			if (d[i][j]) {
				if (i + m[i][j] <= n)	d[i + m[i][j]][j] += d[i][j];
				if (j + m[i][j] <= n)	d[i][j + m[i][j]] += d[i][j];
			}
		}
	}
	cout << d[n][n];
}