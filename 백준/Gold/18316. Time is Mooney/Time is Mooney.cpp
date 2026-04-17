#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, C;
	cin >> N >> M >> C;
	int dp[1001][1001]{};
	vector<vector<int>> V(1001);
	int cost[1001]{};
	for (int i = 1; i <= N; i++)	cin >> cost[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
	}

	set<int> S = { 1 };
	for (int day = 1; day <= 1000; day++) {
		// day일차에 i에서 j로 가기 -> dp[i][day-1]에서 dp[j][day]로 전이
		set<int> temp;
		for (int i : S) {
			for (int j : V[i]) {
				int c = cost[j] - C * (2 * day - 1);
				dp[j][day] = max(dp[j][day], dp[i][day - 1] + c);
				temp.insert(j);
			}
		}
		S = temp;
	}
	int mx = 0;
	for (int i = 1; i <= 1000; i++)	mx = max(mx, dp[1][i]);
	cout << mx;

}