#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, H, W, mxf = 0;
	cin >> N >> H >> W;
	vector<pair<int, int>> F(H);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		mxf = max(mxf, a);
		auto& [p, q] = F[a];
		if (!p)	p = q = b;
		else	p = min(p, b), q = max(q, b);
	}

	int L = F[1].second, R = F[1].second, dp[1001][2]{};
	dp[1][0] = dp[1][1] = L - 1;
	for (int i = 2; i <= mxf; i++) {
		auto& [p, q] = F[i];
		if (!p) { dp[i][0] = dp[i - 1][0] + 100, dp[i][1] = dp[i - 1][1] + 100; continue; }
		dp[i][0] = min(dp[i - 1][0] + 100 + abs(L - q) + abs(p - q), dp[i - 1][1] + 100 + abs(R - q) + abs(p - q));
		dp[i][1] = min(dp[i - 1][0] + 100 + abs(L - p) + abs(p - q), dp[i - 1][1] + 100 + abs(R - p) + abs(p - q));
		L = p, R = q;
	}
	cout << min(dp[mxf][0], dp[mxf][1]);

}