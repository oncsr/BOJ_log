#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
vector<vector<int> > V(1000001);
int dp[1000001][2]{};

void dfs(int n, int p) {
	for (int i : V[n]) {
		if (i != p) {
			dfs(i, n);
			dp[n][0] += dp[i][1];
			dp[n][1] += min(dp[i][0], dp[i][1]);
		}
	}
	dp[n][1]++;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dfs(1, 0);
	cout << min(dp[1][0], dp[1][1]);
}