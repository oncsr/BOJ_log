#include <iostream>
#include <cassert>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[2002]{}, n, m, d[2002][2002]{}, x, y;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = i; j >= 1; j--) {
			if (arr[i] == arr[j])	d[j][i]++;
			d[j][i] += d[j + 1][i - 1];
		}
	}

	for (cin >> m; m--;) {
		cin >> x >> y;
		if (y == x)	cout << "1\n";
		else {
			if ((y - x) / 2 + 1 == d[x][y]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
}