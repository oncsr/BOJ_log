#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, mod = 1e9, ans = 0;

ll dp[101][10][1024]{};
bool vis[101][10][1024]{};

ll cal(int n, int m, int k) {
	if (vis[n][m][k] || n == 0)	return dp[n][m][k];
	vis[n][m][k] = 1;
	if (m - 1 >= 0 && (k & (1 << (m - 1)))) {
		dp[n][m][k] += cal(n - 1, m - 1, k);
		dp[n][m][k] += cal(n - 1, m - 1, k - (1 << m));
	}
	if (m + 1 <= 9 && (k & (1 << (m + 1)))) {
		dp[n][m][k] += cal(n - 1, m + 1, k);
		dp[n][m][k] += cal(n - 1, m + 1, k - (1 << m));
	}
	dp[n][m][k] %= mod;
	return dp[n][m][k];

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	for (int i = 1; i < 10; i++)	dp[1][i][1 << i] = 1, vis[1][i][1 << i] = 1;
	
	cin >> N;
	for (int i = 0; i < 10; i++)	ans = (ans + cal(N, i, 1023)) % mod;
	cout << ans;

}