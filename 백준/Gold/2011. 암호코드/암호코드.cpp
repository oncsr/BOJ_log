#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dp[5001] = { 1,1 };
	string s;
	cin >> s;
	if (s[0] == '0') { cout << 0; return 0; }
	for (int i = 2; i <= s.size(); i++) {
		int now = s[i - 1] - '0', prev = s[i - 2] - '0';
		if (now)	dp[i] = dp[i - 1];
		if (prev && prev * 10 + now <= 26)	dp[i] += dp[i - 2];
		if (!now && (prev > 2 || !prev)) { cout << 0; return 0; }
		dp[i] %= 1000000;
	}
	cout << dp[s.size()] % 1000000;

}