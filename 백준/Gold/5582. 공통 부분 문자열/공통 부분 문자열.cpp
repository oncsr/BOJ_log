#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a, b;
	int dp[4001][4001]{}, mx = 0;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) {
		if (a[i] == b[j]) {
			dp[i][j] = i > 0 && j > 0 ? dp[i - 1][j - 1] + 1 : 1;
		}
		else {
			dp[i][j] = 0;
		}
		mx = max(mx, dp[i][j]);
	}
	cout << mx;

}