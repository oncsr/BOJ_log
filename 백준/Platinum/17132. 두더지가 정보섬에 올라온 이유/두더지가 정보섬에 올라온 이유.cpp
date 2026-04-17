#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<tuple<ll, int, int>> E;
	int root[100001]{};
	vector<int> cnt(100001, 1);
	iota(root, root + N + 1, 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.emplace_back(c, a, b);
	}
	sort(E.begin(), E.end(), greater<>());

	ll s = 0;
	for (auto [c, a, b] : E) {
		int x = find(a), y = find(b);
		root[x] = y;
		s += ((ll)cnt[x] * cnt[y]) * c;
		cnt[y] += cnt[x];
	}
	cout << s;
}