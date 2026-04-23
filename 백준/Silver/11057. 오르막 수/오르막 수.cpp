#include <iostream>
using namespace std;

int main() {
	int n, d[10][1001]{}, m = 10007;
	cin >> n;
	for (int i = 0; i < 10; i++)	d[i][1] = 1;
	for (int i = 2; i <= n; i++)	d[9][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 8; j >= 0; j--) {
			for (int k = 1; k <= i; k++) {
				d[j][i] += d[j + 1][k];
				d[j][i] %= m;

			}
		}
	}
	int s = 0;
	for (int i = 0; i < 10; i++) {
		s += d[i][n];
		s %= m;
	}
	cout << s;
}