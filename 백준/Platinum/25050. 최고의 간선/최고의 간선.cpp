#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<tuple<int, ll, int>>> V(2001);
	vector<pair<int, int>> edge(5001);

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { a,b };
		V[a].emplace_back(b, c, i);
	}

	vector<vector<pair<int, int>>> G;
	int cnt[5001]{};
	function<int(int)> dfs = [&](int n) -> int {
		int res = 0;
		for (auto [i, x] : G[n]) {
			int g = dfs(i);
			cnt[x] += g;
			res += g;
		}
		return res + 1;
	};

	for (int i = 1; i <= N; i++) {
		vector<ll> D(N + 1, -1);
		D[i] = 0;
		vector<int> prev(N + 1);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
		Q.emplace(0, i);
		while (!Q.empty()) {
			auto [d, n] = Q.top();
			Q.pop();
			if (d > D[n])	continue;
			for (auto [i, c, x] : V[n]) {
				ll cost = d + c;
				if (D[i] == -1 || D[i] > cost) {
					D[i] = cost;
					prev[i] = x;
					Q.emplace(cost, i);
				}
			}
		}

		G = vector<vector<pair<int, int>>>(N + 1);
		for (int j = 1; j <= N; j++) {
			if (!prev[j])	continue;
			auto [s, e] = edge[prev[j]];
			G[s].emplace_back(e, prev[j]);
		}

		dfs(i);
	}

	int mx = *max_element(cnt + 1, cnt + M + 1);
	vector<int> ans;
	for (int i = 1; i <= M; i++) {
		if (cnt[i] == mx)	ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int i : ans)	cout << i << ' ';


}