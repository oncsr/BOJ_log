#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int d[21][21][21]{};
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				if (i == 0 || j == 0 || k == 0)	d[i][j][k] = 1;
				else if (i < j && j < k)	d[i][j][k] = d[i][j][k - 1] + d[i][j - 1][k - 1] - d[i][j - 1][k];
				else	d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1] - d[i - 1][j - 1][k - 1];
			}
		}
	}
	int a, b, c;
	for (cin >> a >> b >> c; a != -1 || b != -1 || c != -1; cin >> a >> b >> c) {
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0)	cout << 1;
		else if (a > 20 || b > 20 || c > 20)	cout << d[20][20][20];
		else	cout << d[a][b][c];
		cout << '\n';
	}
}