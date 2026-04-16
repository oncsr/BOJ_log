#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w, l;
	cin >> h >> w >> l;
	char a[200][200]{};
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)cin >> a[i][j];
	string s;
	cin >> s;
	ll dp[200][200][100]{};
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
	int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)if (s[0] == a[i][j])dp[i][j][0] = 1;
	for (int k = 1; k < s.size(); k++)for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) {
		if (s[k] != a[i][j])	continue;
		for (int d = 0; d < 8; d++) {
			int x = i + dx[d], y = j + dy[d];
			if (x < 0 || x >= h || y < 0 || y >= w)	continue;
			dp[i][j][k] += dp[x][y][k - 1];
		}
	}
	ll v = 0;
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)v += dp[i][j][s.size() - 1];
	cout << v;

}