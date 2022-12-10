#include <iostream>
using namespace std;

int main() {
	int n, m, s, a;
	cin >> n >> s >> m;
	int d[1001][52]{}, suc = 1;
	d[s][1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (suc) {
			bool find = 0;
			for (int k = 0; k <= m; k++) {
				if (d[k][i]) {
					if (k + a <= m) {
						d[k + a][i + 1] = i + 1;
						find = 1;
					}
					if (k - a >= 0) {
						d[k - a][i + 1] = i + 1;
						find = 1;
					}
					d[k][i] = 0;
				}
			}
			if (!find)	suc = 0;
		}
	}
	if (suc) {
		int mx = 0;
		for (int i = 0; i <= m; i++) {
			if (d[i][n + 1])	mx = i;
		}
		cout << mx;
	}
	else	cout << -1;
}