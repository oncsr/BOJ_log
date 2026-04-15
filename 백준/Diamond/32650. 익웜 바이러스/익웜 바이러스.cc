#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<ll> a(N + 1);
	ll res = 0, hack = N;
	for (int i = 1; i <= N; i++)	cin >> a[i], res += a[i];

	vector<int> r(N + 1);
	iota(r.begin(), r.end(), 0);
	function<int(int)> F = [&](int x) -> int { return x == r[x] ? x : r[x] = F(r[x]); };

	priority_queue<tuple<ll, int, int, ll>> Q;
	for (int u, v, w; M--; ) {
		cin >> u >> v >> w;
		if (a[u] > a[v])	Q.emplace(a[u] - w, u, v, w);
		else	Q.emplace(a[v] - w, v, u, w);
	}
	
	ll ans = K == N ? res : 1e18;
	while (!Q.empty()) {
		auto [c, u, v, w] = Q.top();	Q.pop();
		int x = F(u), y = F(v);
		if (x == y)	continue;
		if (a[x] - w != c) {
			if (a[x] > a[y])	Q.emplace(a[x] - w, x, y, w);
			else	Q.emplace(a[y] - w, y, x, w);
			continue;
		}
		res -= c;
		r[x] = y;
		if (--hack <= K)	ans = min(ans, res);
	}

	cout << (ans == 1e18 ? -1 : ans);

}