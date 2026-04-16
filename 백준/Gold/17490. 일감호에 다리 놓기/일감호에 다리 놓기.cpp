#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M, K, S[1000001]{}, T[1000001]{};
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	cin >> S[i];
	vector<tuple<ll, int, int>> edge;
	if (M <= 1)	return cout << "YES", 0;
	for (; M--;) {
		int c, d;
		cin >> c >> d;
		int a = min(c, d), b = max(c, d);
		if (a == 1 && b == N)	T[b] = 1e9;
		else	T[a] = 1e9;
	}

	int root[1000002]{};
	iota(root, root + N + 2, 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	for (int i = 1; i <= N; i++) {
		edge.emplace_back(T[i], i, (i % N) + 1);
		edge.emplace_back(S[i], i, N + 1);
	}
	sort(edge.begin(), edge.end());

	ll mst = 0;
	for (auto& [c, a, b] : edge) {
		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		mst += c;
	}
	cout << (mst > K ? "NO" : "YES");

}