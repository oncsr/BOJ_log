#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[16][65536]{};
bool vis[16][65536]{};
int edge[16][16]{};
int N, K;

ll down(int n, int k) {
	if (vis[n][k])	return dp[n][k];
	vis[n][k] = 1;
	int g = k - (1 << n);
	for (int i = 0; i < N; i++) {
		if (!(g & (1 << i)))	continue;
		if (!edge[i][n])	continue;
		dp[n][k] += down(i, g);
	}
	return dp[n][k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	int arr[16]{};
	for (int i = 0; i < N; i++) {
		dp[i][1 << i] = 1;
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if (abs(arr[i] - arr[j]) > K)	edge[i][j] = edge[j][i] = 1;
		}
	}

	ll ans = 0, dest = (1LL << N) - 1;
	for (int i = 0; i < N; i++)	ans += down(i, dest);
	cout << ans;

}