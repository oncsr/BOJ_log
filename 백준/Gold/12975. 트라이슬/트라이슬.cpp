#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int dp[256][256][256]{}, ndp[256][256][256]{};
	cin >> N;

	dp[0][0][0] = 1;
	for (int i = 1, a; i <= N; i++) {
		cin >> a;
		for (int x = 0; x < 256; x++) {
			for (int y = 0; y <= x; y++) {
				for (int z = 0; z <= y; z++) {
					if (!dp[x][y][z])	continue;
					int xx = x ^ a, yy = y ^ a, zz = z ^ a;

					if (xx >= y)	ndp[xx][y][z] = 1;
					else if (xx >= z)	ndp[y][xx][z] = 1;
					else	ndp[y][z][xx] = 1;

					if (yy >= x)	ndp[yy][x][z] = 1;
					else if (yy >= z)	ndp[x][yy][z] = 1;
					else	ndp[x][z][yy] = 1;

					if (zz >= x)	ndp[zz][x][y] = 1;
					else if (zz >= y)	ndp[x][zz][y] = 1;
					else	ndp[x][y][zz] = 1;
				}
			}
		}
		for (int x = 0; x < 256; x++) {
			for (int y = 0; y <= x; y++) {
				for (int z = 0; z <= y; z++) {
					dp[x][y][z] = ndp[x][y][z];
					ndp[x][y][z] = 0;
				}
			}
		}
	}

	int ans = 0;
	for (int x = 0; x < 256; x++) {
		for (int y = 0; y <= x; y++) {
			for (int z = 0; z <= y; z++) {
				if (!dp[x][y][z])	continue;
				ans = max(ans, x + y + z);
			}
		}
	}
	cout << ans;

}