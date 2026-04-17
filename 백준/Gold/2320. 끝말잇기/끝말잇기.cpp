#include <bits/stdc++.h>
using namespace std;

int N;
int dp[16][65536]{};
int edge[16][16]{};
string arr[16]{};

int D(int n, int k) {
	if (dp[n][k])	return dp[n][k];
	int g = k - (1 << n);
	for (int i = 0; i < N; i++) {
		if (!(g & (1 << i)))	continue;
		if (arr[i].back() != arr[n].front())	continue;
		dp[n][k] = max(dp[n][k], D(i, g) + edge[i][n]);
	}
	return dp[n][k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)	continue;
			if (arr[i].back() == arr[j].front())	edge[i][j] = arr[j].size();
		}
	}

	for (int i = 0; i < N; i++)	dp[i][1 << i] = arr[i].size();

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = (1 << N) - 1; j > 0; j--) {
			if (!(j & (1 << i)))	continue;
			ans = max(ans, D(i, j));
		}
	}
	cout << ans;

}