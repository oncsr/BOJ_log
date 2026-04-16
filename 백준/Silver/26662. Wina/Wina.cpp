#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k, c[2020][2020]{}, a[2020][2020]{};
	cin >> n >> k;
	for (int i = 1; i <= n; i++)	for (int j = 1; j <= i; j++)	cin >> a[i][j];
	c[1][1] = 1;
	int ans = a[1][1];
	for (int x = 2; x <= n; x++) {
		for (int s = 1, e = x; s <= e; s++, e--) {
			c[x][s] = c[x][e] = c[x - 1][s] + s;
			if (c[x][s] <= k)	ans = min({ ans, a[x][s], a[x][e] });
		}
	}
	cout << ans;
}