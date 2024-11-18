#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		for (auto& i : arr)	cin >> i;
		int ans = 0;
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			ans += max(0, arr[i][j] - (i + 1 == n ? '0' : arr[i + 1][j]));
			ans += max(0, arr[i][j] - (i == 0 ? '0' : arr[i - 1][j]));
			ans += max(0, arr[i][j] - (j + 1 == m ? '0' : arr[i][j + 1]));
			ans += max(0, arr[i][j] - (j == 0 ? '0' : arr[i][j - 1]));
			if (arr[i][j] != '0')	ans += 2;
		}
		cout << ans << '\n';
	}

}