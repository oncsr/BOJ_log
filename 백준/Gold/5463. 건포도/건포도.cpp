#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, R[51][51]{}, dp[51][51][51][51]{};

int sol(int sx, int sy, int ex, int ey) {
	if (sx == ex && sy == ey) return 0;
	if (dp[sx][sy][ex][ey]) return dp[sx][sy][ex][ey];
	dp[sx][sy][ex][ey] = R[ex][ey] - R[sx - 1][ey] - R[ex][sy - 1] + R[sx - 1][sy - 1];
	int res = 1e9;
	for (int k = sx; k < ex; k++) res = min(res, sol(sx, sy, k, ey) + sol(k + 1, sy, ex, ey));
	for (int k = sy; k < ey; k++) res = min(res, sol(sx, sy, ex, k) + sol(sx, k + 1, ex, ey));
	dp[sx][sy][ex][ey] += res;
	return dp[sx][sy][ex][ey];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> R[i][j], R[i][j] += R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1];
	
	cout << sol(1, 1, N, M);

}