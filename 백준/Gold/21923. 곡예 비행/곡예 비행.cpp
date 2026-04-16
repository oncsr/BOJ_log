#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, arr[1002][1002]{}, up[1002][1002]{}, down[1002][1002]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++)	cin >> arr[i][j];

	for (int j = 1; j <= M; j++)	up[N][j] = up[N][j - 1] + arr[N][j];
	for (int j = M; j >= 1; j--)	down[N][j] = down[N][j + 1] + arr[N][j];
	for (int i = N; i >= 1; i--) {
		up[i][1] = up[i + 1][1] + arr[i][1];
		down[i][M] = down[i + 1][M] + arr[i][M];
	}

	for (int i = N - 1; i >= 1; i--)	for (int j = 2; j <= M; j++) {
		up[i][j] = arr[i][j];
		up[i][j] += max(up[i + 1][j], up[i][j - 1]);
	}

	for (int i = N - 1; i >= 1; i--)	for (int j = M - 1; j >= 1; j--) {
		down[i][j] = arr[i][j];
		down[i][j] += max(down[i + 1][j], down[i][j + 1]);
	}

	int ans = -1e9;
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++) {
		ans = max(ans, down[i][j] + up[i][j]);
	}
	cout << ans;

}