#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;
	int B1[2001][2001]{}, B2[2001][2001]{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			if (a == 'B') {
				if ((i ^ j) & 1)	B2[i][j]++;
				else	B1[i][j]++;
			}
			B1[i][j] += B1[i - 1][j] + B1[i][j - 1] - B1[i - 1][j - 1];
			B2[i][j] += B2[i - 1][j] + B2[i][j - 1] - B2[i - 1][j - 1];
		}
	}
	int mn = 4000001;
	for (int i = 1; i + k - 1 <= n; i++) {
		for (int j = 1; j + k - 1 <= m; j++) {
			int a = B1[i + k - 1][j + k - 1] - B1[i - 1][j + k - 1] - B1[i + k - 1][j - 1] + B1[i - 1][j - 1];
			int b = B2[i + k - 1][j + k - 1] - B2[i - 1][j + k - 1] - B2[i + k - 1][j - 1] + B2[i - 1][j - 1];
			if ((i ^ j) & 1)	swap(a, b);
			int g = (k * k + 1) >> 1;
			mn = min(mn, min(g - a + b, a + k * k - g - b));
		}
	}
	cout << mn;
}