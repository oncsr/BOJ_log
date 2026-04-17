#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int arr[1025][1025]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j];

	int dp[1025][1025]{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	for (; M--;) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int res = dp[ex][ey] - dp[sx - 1][ey] - dp[ex][sy - 1] + dp[sx - 1][sy - 1];
		cout << res << '\n';
	}

}