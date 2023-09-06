#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int r, c;
	cin >> r >> c;
	ii sum[750][750]{};
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char a;
			cin >> a;
			if (a == '0') {
				sum[i][j] = { 0,0 };
				continue;
			}
			ans = max(ans, 1);
			if (i && j)	sum[i][j].first = sum[i - 1][j - 1].first + 1;
			else	sum[i][j].first = 1;
			if (i && j < c - 1)	sum[i][j].second = sum[i - 1][j + 1].second + 1;
			else	sum[i][j].second = 1;

			int l = min({ i / 2, j, c - j - 1, sum[i][j].first - 1, sum[i][j].second - 1 });
			// k+1인 다이아몬드가 있는가?
			for (int k = 1; k <= l; k++) {
				if (sum[i - k][j - k].second >= k + 1 && sum[i - k][j + k].first >= k + 1)
					ans = max(ans, k + 1);
			}

		}
	}
	cout << ans;
}