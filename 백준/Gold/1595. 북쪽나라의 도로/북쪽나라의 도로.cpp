#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> V(10001);
int ans = 0;

int dfs(int n, int p) {
	int mx1 = 0, mx2 = 0;
	for (auto[i, c] : V[n]) {
		if (i == p) continue;
		int g = dfs(i, n) + c;
		if (g > mx1) mx2 = mx1, mx1 = g;
		else if (g > mx2) mx2 = g;
	}
	ans = max(ans, mx1 + mx2);
	return mx1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b, c;
	while (cin >> a >> b >> c) {
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	for (int i = 1;i <= 10000; i++) {
		if (V[i].empty()) continue;
		dfs(i,0);
		cout << ans;
		return 0;
	}
	cout << 0;

}