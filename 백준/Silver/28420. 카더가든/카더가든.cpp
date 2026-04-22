#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[301][301]{}, n, m, a, b, c, mn = 1e9;
	cin >> n >> m >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i + a - 1 <= n && j + b + c - 1 <= m) {
				int t = arr[i + a - 1][j + b + c - 1] - arr[i - 1][j + b + c - 1] - arr[i + a - 1][j - 1] + arr[i - 1][j - 1];
				mn = min(t, mn);
			}
			if (i + a + b - 1 <= n && j + c + a - 1 <= m) {
				int t1 = arr[i + a - 1][j + c - 1] - arr[i - 1][j + c - 1] - arr[i + a - 1][j - 1] + arr[i - 1][j - 1];
				int t2 = arr[i + a + b - 1][j + c + a - 1] - arr[i + a - 1][j + c + a - 1] - arr[i + a + b - 1][j + c - 1] + arr[i + a - 1][j + c - 1];
				mn = min(t1 + t2, mn);
			}
			if (i + a + c - 1 <= n && j + b + a - 1 <= m) {
				int t1 = arr[i + a - 1][j + b - 1] - arr[i - 1][j + b - 1] - arr[i + a - 1][j - 1] + arr[i - 1][j - 1];
				int t2 = arr[i + a + c - 1][j + b + a - 1] - arr[i + a - 1][j + b + a - 1] - arr[i + a + c - 1][j + b - 1] + arr[i + a - 1][j + b - 1];
				mn = min(t1 + t2, mn);
			}
		}
	}
	cout << mn;
}