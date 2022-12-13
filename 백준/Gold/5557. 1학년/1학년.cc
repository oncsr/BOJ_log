#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, a;
	ll d[21][101]{};
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a;
		if (i == 1) {
			d[a][i + 1] = 1;
			continue;
		}
		for (int j = 0; j <= 20; j++) {
			if (d[j][i]) {
				if (j + a <= 20)	d[j + a][i + 1] += d[j][i];
				if (j - a >= 0)	d[j - a][i + 1] += d[j][i];
				d[j][i] = 0;
			}
		}
	}
	cin >> a;
	cout << d[a][n];
}