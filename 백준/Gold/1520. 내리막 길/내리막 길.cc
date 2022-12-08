#include <iostream>
using namespace std;

int main() {
	int N, M, m[501][501]{}, d[501][501]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> m[i][j];
			if (i == 1) {
				if (j == 1)	d[i][j] = 1;
				else {
					if (m[i][j] < m[i][j - 1])	d[i][j] = d[i][j - 1];
				}
			}
			else {
				if (m[i][j] < m[i - 1][j])	d[i][j] = d[i - 1][j];
				if (m[i][j] < m[i][j - 1])	d[i][j] += d[i][j - 1];
			}
		}
	}
	int k = 100;
	while (k--) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == 1 && j == 1)	continue;
				int t = 0;
				if (m[i][j] < m[i - 1][j])	t += d[i - 1][j];
				if (m[i][j] < m[i + 1][j])	t += d[i + 1][j];
				if (m[i][j] < m[i][j - 1])	t += d[i][j - 1];
				if (m[i][j] < m[i][j + 1])	t += d[i][j + 1];
				d[i][j] = t;
			}
		}
	}
	cout << d[N][M];
}