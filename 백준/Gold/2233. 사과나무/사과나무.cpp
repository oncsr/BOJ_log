#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, now = 0, next = 0, x, y, X, Y, par[2001]{}, dep[2001]{}, c = 0;
	string s;
	vector<vector<int>> V(2001);
	pair<int, int> pos[2001]{};
	cin >> N >> s >> x >> y;
	for (char i : s) {
		if (i == '0') {
			par[++next] = now;
			V[now].push_back(next);
			pos[next].first = ++c;
			V[next].push_back(now);
			now = next;
			if (c == x)	X = now;
			if (c == y)	Y = now;
		}
		else {
			pos[now].second = ++c;
			if (c == x)	X = now;
			if (c == y)	Y = now;
			now = par[now];
		}
	}

	function<void(int, int, int)> dfs = [&](int n, int p, int d) -> void {
		dep[n] = d;
		for (int i : V[n]) {
			if (i == p)	continue;
			dfs(i, n, d + 1);
		}
	};
	dfs(0, -1, 0);

	while (X != Y) {
		if (dep[X] > dep[Y])	X = par[X];
		else	Y = par[Y];
	}
	cout << pos[X].first << ' ' << pos[X].second;

}