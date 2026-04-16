#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> V(N);
	vector<int> B(K);
	for (auto& [a, b] : V)	cin >> b >> a;
	for (int& i : B)	cin >> i;
	sort(V.begin(), V.end(), greater<>());
	sort(B.begin(), B.end());

	vector<int> root(K + 1);
	iota(root.begin(), root.end(), 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	ll ans = 0;
	for (auto& [a, b] : V) {
		int p = lower_bound(B.begin(), B.end(), b) - B.begin();
		int x = find(p);
		if (x == K)	continue;
		ans += a;
		int y = find(x + 1);
		root[x] = y;
	}
	cout << ans;

}