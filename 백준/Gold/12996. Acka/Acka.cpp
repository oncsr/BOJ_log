#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll dp[51][51][51][51]{}, S, A, B, C, m = 1e9 + 7;
	dp[0][0][0][0] = 1;
	cin >> S >> A >> B >> C;

	for (int s = 1; s <= S; s++) {
		for (int a = 0; a <= A; a++)	for (int b = 0; b <= B; b++)	for (int c = 0; c <= C; c++) {
			ll &v = dp[s][a][b][c];
			// a
			if (a)	v += dp[s - 1][a - 1][b][c];
			// b
			if (b)	v += dp[s - 1][a][b - 1][c];
			// c
			if (c)	v += dp[s - 1][a][b][c - 1];
			// a,b
			if (a && b)	v += dp[s - 1][a - 1][b - 1][c];
			// a,c
			if (a && c)	v += dp[s - 1][a - 1][b][c - 1];
			// b,c
			if (b && c)	v += dp[s - 1][a][b - 1][c - 1];
			// a,b,c
			if (a && b && c)	v += dp[s - 1][a - 1][b - 1][c - 1];
			v %= m;
		}
	}
	cout << dp[S][A][B][C];

}