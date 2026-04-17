#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int root[1000000]{};
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};
	iota(root, root + N * M, 0);
	
	auto up = [&](int n) -> int { return n / M != 0 ? n - M : -1; };
	auto down = [&](int n) -> int { return n / M != N - 1 ? n + M : -1; };
	auto left = [&](int n) -> int { return n % M != 0 ? n - 1 : -1; };
	auto right = [&](int n) -> int { return n % M != M - 1 ? n + 1 : -1; };

	vector<pair<ll, int>> V;
	for (int i = 0; i < N * M; i++) {
		int a;
		cin >> a;
		V.emplace_back(a, i);
	}
	sort(V.begin(), V.end());

	ll val[1000000]{};
	for (int i = 0; i < N * M; i++)	cin >> val[i];

	ll ans[1000000]{};
	auto cal = [&](int a, int b) -> void {
		int x = find(a), y = find(b);
		if (x == y)	return;
		root[x] = y;
		val[y] += val[x];
		ans[b] = max(ans[b], val[y]);
	};
	bitset<1000000> vis;

	int i = 0;
	while (i < N * M) {
		int H = V[i].first;
		queue<int> Q;
		while (i < N * M && V[i].first == H) {
			auto& [h, n] = V[i];
			Q.push(n);
			int u = up(n), d = down(n), l = left(n), r = right(n);
			if (u != -1 && vis[u])	cal(u, n);
			if (d != -1 && vis[d])	cal(d, n);
			if (l != -1 && vis[l])	cal(l, n);
			if (r != -1 && vis[r])	cal(r, n);
			vis.flip(n);
			i++;
		}
		while (!Q.empty()) {
			int n = Q.front();
			Q.pop();
			ans[n] = val[find(n)];
		}
	}

	for (int i = 0; i < N * M; i++) {
		cout << ans[i] << ' ';
		if (i % M == M - 1)	cout << '\n';
	}

}