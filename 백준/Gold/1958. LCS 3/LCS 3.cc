#include <iostream>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int d[101][101][101]{};
	int mx = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			for (int k = 0; k < c.size(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) {
					d[i + 1][j + 1][k + 1] = d[i][j][k] + 1;
				}
				else {
					d[i + 1][j + 1][k + 1] = max(
						d[i][j + 1][k + 1], max(d[i + 1][j][k + 1], d[i + 1][j + 1][k])
					);
				}
				mx = max(mx, d[i + 1][j + 1][k + 1]);
			}
		}
	}
	cout << mx;
}