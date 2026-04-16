#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V(100001);
tuple<int, int, int> par[100001]{};

void dfs(int n, int p, int s) {
	for (auto [i, c] : V[n]) {
		if (i == p)	continue;
		par[i] = { n, c, s + c };
		dfs(i, n, s + c);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, A, B;
	cin >> N >> A >> B;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	dfs(A, 0, 0);

	if (A == B)	return cout << 0, 0;
	int ans = 2e9, s = 0;
	while (B != A) {
		auto [p, c, t] = par[B];
		ans = min(ans, s + t - c);
		s += c;
		B = p;
	}
	cout << ans;


}