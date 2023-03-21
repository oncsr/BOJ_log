#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	for (cin >> N; N != -1; cin >> N) {
		char map[100][100]{};
		long long ans[100][100]{};
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		ans[0][0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '0')	continue;
				if (!ans[i][j])	continue;
				int right = j + (map[i][j] - '0');
				int down = i + (map[i][j] - '0');
				if (right < N)	ans[i][right] += ans[i][j];
				if (down < N)	ans[down][j] += ans[i][j];
			}
		}
		cout << ans[N - 1][N - 1] << '\n';
	}
}