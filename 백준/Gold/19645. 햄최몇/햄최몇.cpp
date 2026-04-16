#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int dp[2501][2501]{}, ndp[2501][2501]{};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int INF = 2e9;
	int n, a[50]{};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	dp[0][0] = 1;
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];

		for (int p = 0; p <= 50 * (i + 1); p++) {
			for (int q = 0; q <= p; q++) {
				if (!dp[p][q]) continue;
				int x1 = p + a[i], y1 = q;
				int x2 = p, y2 = q + a[i];
				ndp[max(x1, y1)][min(x1, y1)] = 1;
				ndp[max(x2, y2)][min(x2, y2)] = 1;
				int temp[3] = { p,q,s - (p + q) };
				sort(temp, temp + 3);
				ndp[temp[2]][temp[1]] = 1;
			}
		}
		for (int p = 0; p <= 50 * (i + 1); p++) {
			for (int q = 0; q <= p; q++) {
				dp[p][q] = ndp[p][q];
				ndp[p][q] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 2500; i++) for (int j = 0; j <= i; j++) if (dp[i][j]) ans = max(ans, s - (i + j));
	cout << ans;

}