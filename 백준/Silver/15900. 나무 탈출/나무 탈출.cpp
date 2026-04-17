#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int>> V(N + 1);
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	ll res = 0;
	function<void(int, int, int)> dfs = [&](int n, int p, int v) -> void {
		int child = 0;
		for (int i : V[n]) {
			if (i == p)	continue;
			child++;
			dfs(i, n, v + 1);
		}
		if (!child)	res += v;
	};
	dfs(1, 0, 0);

	cout << ((res & 1) ? "Yes" : "No");

}