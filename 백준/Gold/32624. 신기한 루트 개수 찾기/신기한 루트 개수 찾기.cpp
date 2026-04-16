#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, A, B;
	cin >> N >> A >> B;
	if (A > B)	swap(A, B);
	vector<vector<int>> V(N + 1);
	for (int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		if (min(a, b) == A && max(a, b) == B)	return cout << 0, 0;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int ans = N, g = 0;
	function<void(int, int)> dfs = [&](int n, int p) -> void {
		if (n == B) { g = p; return; }
		for (int i : V[n]) {
			if (i == p)	continue;
			dfs(i, n);
		}
	};
	dfs(A, 0);
	function<void(int, int, int)> dfs2 = [&](int n, int p, int d) -> void {
		ans -= d |= (n == A || n == B);
		for (int i : V[n]) {
			if (i == p)	continue;
			dfs2(i, n, d);
		}
	};
	dfs2(g, 0, 0);
	cout << ans;

}