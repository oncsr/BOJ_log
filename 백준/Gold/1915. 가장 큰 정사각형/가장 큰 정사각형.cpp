#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int L[1001][1001]{}, U[1001][1001]{}, D[1001][1001]{}, n, m, s = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			if (a == '0') {
				L[i][j] = U[i][j] = 0;
				continue;
			}
			L[i][j] = L[i][j - 1] + 1;
			U[i][j] = U[i - 1][j] + 1;
			if (L[i][j] >= D[i - 1][j - 1] + 1 && U[i][j] >= D[i - 1][j - 1] + 1)
				D[i][j] = D[i - 1][j - 1] + 1;
			else	D[i][j] = min(L[i][j], U[i][j]);
			s = max(s, D[i][j]);
		}
	}
	cout << s * s;
}