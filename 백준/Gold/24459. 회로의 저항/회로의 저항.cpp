#include <bits/stdc++.h>
using namespace std;

int deg[100001]{};
vector<vector<pair<int, int>>> V(100001);
int mx = 0, mn = 1e9 + 1;

pair<int, int> dfs1(int n, int p) {
	int mx1 = 0, mx2 = 0, mn1 = 1e9 + 1, mn2 = 1e9 + 1;
	for (auto& [i, c] : V[n]) {
		if (i == p)	continue;
		auto [res, res2] = dfs1(i, n);
		if (res + c > mx1)	mx2 = mx1, mx1 = res + c;
		else if (res + c > mx2)	mx2 = res + c;
		if (res2 + c < mn1)	mn2 = mn1, mn1 = res2 + c;
		else if (res2 + c < mn2)	mn2 = res2 + c;
	}
	mx = max(mx, mx1 + mx2);
	if (deg[n] == 1)	mn = min(mn, mn1);
	else	mn = min(mn, mn1 + mn2);
	return { mx1, mn1 == 1e9 + 1 ? 0 : mn1 };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		deg[a]++, deg[b]++;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	dfs1(0, -1);
	cout << mx << '\n' << mn;


}