#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ans;
	char arr[50][50]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	cin >> arr[i][j];

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#')	continue;
			bool garo = 0, sero = 0;
			if (j == 0 || arr[i][j - 1] == '#') {
				int cnt = 0;
				for (int k = j + 1; k < m; k++) {
					if (arr[i][k] == '#')	break;
					cnt++;
				}
				if (cnt >= 2)	garo = 1;
			}
			if (i == 0 || arr[i-1][j] == '#') {
				int cnt = 0;
				for (int k = i + 1; k < n; k++) {
					if (arr[k][j] == '#')	break;
					cnt++;
				}
				if (cnt >= 2)	sero = 1;
			}
			if (garo || sero)	ans.emplace_back(i+1, j+1);
		}
	}
	cout << ans.size() << '\n';
	for (auto [a, b] : ans)	cout << a << ' ' << b << '\n';

}