#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int d[101][10001]{}, a[101][10001]{}, s[101][10001]{};
	int N, K, g = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int mx = 0, mx2 = 0, id1 = 0, id2 = 0;
		for (int j = 1; j <= K; j++) {
			cin >> a[i][j];
			if (i == 1)	s[i][j] = a[i][j];
			else	s[i][j] = d[i - 1][j] + a[i][j];
		}

		for (int j = 1; j <= K; j++) {
			if (mx == 0) {
				mx = s[i][j];
				id1 = j;
			}
			else if (mx2 == 0) {
				if (s[i][j] > mx) {
					mx2 = mx;
					id2 = id1;
					mx = s[i][j];
					id1 = j;
				}
				else {
					mx2 = s[i][j];
					id2 = j;
				}
			}
			else {
				if (s[i][j] > mx) {
					mx2 = mx;
					id2 = id1;
					mx = s[i][j];
					id1 = j;
				}
				else if (s[i][j] > mx2) {
					mx2 = s[i][j];
					id2 = j;
				}
			}
		}

		for (int j = 1; j <= K; j++) {
			if (j == id1)	d[i][j] = mx2;
			else	d[i][j] = mx;
		}
	}
	for (int j = 1; j <= K; j++) {
		g = max(g, s[N][j]);
	}
	cout << g;
}