#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edge(m);
	for (auto& [a, b] : edge)	cin >> a >> b;

	int root[2000]{};
	iota(root, root + 2000, 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	vector<ll> D(2000);
	ll mod = 1e9 + 7, ans = 0;
	D[0] = 1;
	for (int i = 1; i < 2000; i++)	D[i] = (D[i - 1] * 3) % mod;
	reverse(edge.begin(), edge.end());
	int k = m - 1;
	for (auto& [a, b] : edge) {
		int x = find(a), y = find(b);
		if ((x == 0 && y == n - 1) || (x == n - 1 && y == 0)) {
			ans = (ans + D[k]) % mod;
		}
		else {
			if (x == 0 || x == n - 1)	root[y] = x;
			else	root[x] = y;
		}
		k--;
	}
	cout << ans;

}	