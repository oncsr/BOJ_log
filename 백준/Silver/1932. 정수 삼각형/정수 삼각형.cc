#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);	cout.tie(0);
	int n, mx = 0;
	cin >> n;
	int d[501][501]{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> d[i][j];
			d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
			mx = max(mx, d[i][j]);
		}
	}
	cout << mx;
}