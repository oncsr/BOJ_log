#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, p[200001]{}, c[200001]{}, d[200001]{};
	vector<vector<int>> V(200001);
	cin >> n;
	for (int i = 2; i <= n; i++)	cin >> p[i], V[p[i]].push_back(i);
	function<int(int)> Dfs = [&](int n) -> int {
		c[n] = 1;
		for (int i : V[n])	c[n] += Dfs(i);
		return c[n];
	};

	cout << "0 ";

	Dfs(1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
	for (int i = 1; i <= n; i++)	if (c[i] == 1)	q.emplace(c[i] - 1, i);
	ll ans = 0;
	while (!q.empty()) {
		auto [v, w] = q.top(); q.pop();
		ans += v;
		cout << ans << ' ';
		d[p[w]] += c[w];
		if (d[p[w]] == c[p[w]] - 1)	q.emplace(c[p[w]] - 1, p[w]);
	}

}