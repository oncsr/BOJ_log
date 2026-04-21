#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V(30001);
int vis[30001]{};
int arr[30001]{};

pair<int, int> dfs(int n) {
	pair<int, int> r = { arr[n], 1 };
	vis[n]++;
	for (int i : V[n]) {
		if (vis[i])	continue;
		pair<int, int> p = dfs(i);
		r.first += p.first;
		r.second += p.second;
	}
	return r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	vector<pair<int, int>> L;
	for (int i = 1; i <= N; i++) {
		if (vis[i])	continue;
		L.push_back(dfs(i));
	}
	int dp[3030]{};
	for (int i = 0; i < L.size(); i++) {
		int g = L[i].second, v = L[i].first;
		if (g >= K)	continue;
		for (int j = K - 1; j >= g; j--) {
			if (!dp[j - g])	continue;
			dp[j] = max(dp[j], dp[j - g] + v);
		}
		dp[g] = max(dp[g], v);
	}
	int mx = 0;
	for (int i = 0; i < K; i++)	mx = max(mx, dp[i]);
	cout << mx;


}