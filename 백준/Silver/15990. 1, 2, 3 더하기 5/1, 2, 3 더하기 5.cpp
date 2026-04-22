#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int d[100001][3]{}, mod = 1e9 + 9;
	d[1][0] = 1;
	d[2][1] = 1;
	d[3][0] = 1, d[3][1] = 1, d[3][2] = 1;
	for (int i = 4; i <= 100000; i++) {
		d[i][0] = (d[i - 1][1] + d[i - 1][2]) % mod;
		d[i][1] = (d[i - 2][0] + d[i - 2][2]) % mod;
		d[i][2] = (d[i - 3][0] + d[i - 3][1]) % mod;
	}
	int TC;
	for (cin >> TC; TC--;) {
		int n;
		cin >> n;
		cout << ((d[n][0] + d[n][1]) % mod + d[n][2]) % mod << '\n';
	}
}