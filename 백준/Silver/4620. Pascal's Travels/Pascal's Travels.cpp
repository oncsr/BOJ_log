#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n > 0) {
		int m[35][35];
		long long d[35][35]{};
		string a;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			for (int j = 1; j <= n; j++)
				m[i][j] = a[j - 1] - '0';
		}
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
		cout << d[n][n] << '\n';
		cin >> n;
	}
}