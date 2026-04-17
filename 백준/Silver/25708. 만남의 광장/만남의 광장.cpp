#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	int arr[101][101]{}, row[101]{}, col[101]{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			arr[i][j] = a;
			row[i] += a;
			col[j] += a;
		}
	}

	int ans = -1e9;
	for (int a = 1; a <= n; a++) {
		int p = row[a];
		for (int b = a + 1; b <= n; b++) {
			int q = row[b];
			for (int c = 1; c <= m; c++) {
				int r = col[c] - arr[a][c] - arr[b][c];
				for (int d = c + 1; d <= m; d++) {
					int s = col[d] - arr[a][d] - arr[b][d];
					int e = (b - a - 1) * (d - c - 1);
					ans = max(ans, p + q + r + s + e);
				}
			}
		}
	}
	cout << ans;

}