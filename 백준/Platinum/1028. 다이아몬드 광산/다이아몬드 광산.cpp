#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int r, c;
	cin >> r >> c;
	int L[752][752]{};
    int R[752][752]{};
	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char a;
			cin >> a;
			if (a == '0') {
                L[i][j] = R[i][j] = 0;
				continue;
			}
			ans = max(ans, 1);
            L[i][j] = L[i - 1][j - 1] + 1;
            R[i][j] = R[i - 1][j + 1] + 1;

			int l = min({ (i - 1) / 2, j - 1, c - j, L[i][j] - 1, R[i][j] - 1 });
			// k+1인 다이아몬드가 있는가?
			for (int k = ans; k <= l; k++) {
				if (R[i - k][j - k] >= k + 1 && L[i - k][j + k] >= k + 1)
					ans = max(ans, k + 1);
			}

		}
	}
	cout << ans;
}