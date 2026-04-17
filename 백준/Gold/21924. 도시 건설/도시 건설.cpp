#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<tuple<ll, int, int>> E;
	int root[300001]{};
	iota(root, root + N + 1, 0);

	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	ll ans = 0, cnt = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.emplace_back(c, a, b);
		ans += c;
	}
	sort(E.begin(), E.end());
	for (auto [c, a, b] : E) {
		int x = find(a), y = find(b);
		if (x == y)	continue;
		cnt++;
		ans -= c;
		root[x] = y;
	}
	cout << (cnt == N - 1 ? ans : -1);

}