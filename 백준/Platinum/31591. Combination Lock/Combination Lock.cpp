#include <bits/stdc++.h>
using namespace std;

int A[50]{}, B[50]{}, N;
int sosu[15] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
int ch[51]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 2; i <= 50; i++) {
		int t = i;
		for (int j = 0; sosu[j] * sosu[j] <= t; j++) {
			if (t % sosu[j])	continue;
			while (t % sosu[j] == 0)	t /= sosu[j];
			ch[i] |= (1 << j);
		}
		if (t != 1) {
			for (int j = 0;; j++) {
				if (sosu[j] == t) { ch[i] |= (1 << j); break; }
			}
		}
	}
	
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> A[i] >> B[i];
	
	vector<vector<int>> dp(1 << 15);
	for (int i = A[0]; i <= B[0]; i++)	dp[ch[i]] = { i };
	for (int i = 1; i < N; i++) {
		vector<vector<int>> next(1 << 15);
		for (int c = A[i]; c <= B[i]; c++) {
			for (int k = 0; k < (1 << 15); k++) {
				if (dp[k].empty())	continue;
				if (k & ch[c])	continue;
				next[k | ch[c]] = dp[k];
				next[k | ch[c]].push_back(c);
			}
		}
		dp = next;
	}
	for (int i = 0; i < (1 << 15); i++) {
		if (dp[i].empty())	continue;
		for (int j : dp[i])	cout << j << ' ';
		return 0;
	}
	cout << -1;

}