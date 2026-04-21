#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K, S, T;
	cin >> N >> M >> K >> S >> T;

	vector<vector<ll>> dp(100001, vector<ll>(11, -1));
	vector<vector<pair<int, ll>>> ski(100001);	// ski[i] = i로 올 수 있는 간선 집합
	vector<vector<int>> lift(100001);
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		ski[b].push_back({ a,t });
		lift[a].push_back(b);
	}
	dp[S][0] = 0;
	for (int i = S; i <= N; i++) {
		for (auto j : ski[i]) {
			int prev = j.first;
			ll cost = j.second;
			if (dp[prev][0] == -1)	continue;
			if (dp[i][0] == -1)	dp[i][0] = dp[prev][0] + cost;
			else	dp[i][0] = max(dp[i][0], dp[prev][0] + cost);
		}
	}

	for (int g = 1; g <= K; g++) {
		for (int i = N; i >= 1; i--) {
			for (auto j : lift[i]) {
				if (dp[j][g - 1] == -1)	continue;
				if (dp[i][g] == -1)	dp[i][g] = dp[j][g - 1];
				else	dp[i][g] = max(dp[i][g], dp[j][g - 1]);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (auto j : ski[i]) {
				int prev = j.first;
				ll cost = j.second;
				if (dp[prev][g] == -1)	continue;
				if (dp[i][g] == -1)	dp[i][g] = dp[prev][g] + cost;
				else	dp[i][g] = max(dp[i][g], dp[prev][g] + cost);
			}
		}
	}

	cout << dp[T][K];


}