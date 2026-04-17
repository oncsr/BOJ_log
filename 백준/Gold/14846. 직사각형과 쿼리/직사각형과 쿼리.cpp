#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	int sum[301][301][11]{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			for (int k = 1; k <= 10; k++) {
				sum[i][j][k] = (a == k) + sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
			}
		}
	}

	int Q;
	for (cin >> Q; Q--;) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int cnt = 0;
		for (int k = 1; k <= 10; k++) {
			int g = sum[c][d][k] - sum[a - 1][d][k] - sum[c][b - 1][k] + sum[a - 1][b - 1][k];
			if (g)	cnt++;
		}
		cout << cnt << '\n';
	}

}