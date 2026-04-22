#include <bits/stdc++.h>
using namespace std;

int dp[10001]{}, N;
vector<vector<int>> V(10001);

int dfs(int n, int p) {
	int s = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		int g = dfs(i, n);
		dp[n] = max(dp[n], g);
		s += g;
	}
	dp[n] = max(dp[n], N - s);
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] <= N / 2) {
			cnt++;
			cout << i << '\n';
		}
	}
	if (!cnt)	cout << "NONE";

}