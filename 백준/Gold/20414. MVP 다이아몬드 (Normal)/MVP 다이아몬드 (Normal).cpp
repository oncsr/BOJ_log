#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, s, g, p, d;
	string A;
	cin >> N >> s >> g >> p >> d >> A;

	map<char, int> M;
	M['B'] = s - 1, M['S'] = g - 1, M['G'] = p - 1, M['P'] = d - 1, M['D'] = d;

	int dp[37][501]{};
	for (int i = 1; i <= M[A[0]]; i++)	dp[1][i] = i;
	for (int i = 2; i <= N; i++) {
		int mx = M[A[i - 1]];
		for (int j = 0; j <= mx; j++) {
			for (int k = 0; k <= M[A[i - 2]]; k++) {
				if (j + k > mx && mx != d)	break;
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + j);
			}
		}
	}
	cout << *max_element(dp[N], dp[N] + 501);

}