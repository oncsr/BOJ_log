#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, ll>>> V(200001);

	for (; M--;) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		V[a].emplace_back(b, c + d);
		V[b].emplace_back(a, c + d);
	}

	bool minus = 0;
	bitset<200001> vis;
	function<void(int)> dfs = [&](int n) -> void {
		for (auto [i, c] : V[n]) {
			if (c < 0)	minus = 1;
			if (vis[i])	continue;
			vis[i] = 1;
			dfs(i);
		}
	};
	vis[1] = 1;
	dfs(1);
	if (minus) {
		vector<int> ans;
		for (int i = 2; i <= N; i++) {
			if (vis[i])	ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for (int i : ans)	cout << i << ' ';
		return 0;
	}

	ll T;
	cin >> T;
	T <<= 1;

	vector<ll> D(N + 1, -1);
	D[1] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	Q.emplace(0, 1);
	while (!Q.empty()) {
		auto [d, n] = Q.top();	Q.pop();
		if (d > D[n])	continue;
		for (auto [i, c] : V[n]) {
			if (D[i] == -1 || D[i] > d + c) {
				D[i] = d + c;
				Q.emplace(d + c, i);
			}
		}
	}

	vector<int> ans;
	for (int i = 2; i <= N; i++) {
		if (D[i] == -1)	continue;
		if (D[i] <= T)	ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)	cout << i << ' ';

}