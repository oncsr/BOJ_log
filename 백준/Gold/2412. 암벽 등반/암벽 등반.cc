#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T;
	cin >> N >> T;
	map<pair<int, int>, int> V;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		V[{a, b}] = i;
	}
	
	int vis[50001]{};
	queue<tuple<int, int, int>> Q;
	Q.emplace(0, 0, 0);
	
	while (!Q.empty()) {
		auto [x, y, t] = Q.front();
		Q.pop();
		if (y == T)	return cout << t, 0;
		for (int xx = x - 2; xx <= x + 2; xx++)	for (int yy = y - 2; yy <= y + 2; yy++) {
			if (V.find(make_pair(xx, yy)) == V.end())	continue;
			if (vis[V[{xx, yy}]])	continue;
			vis[V[{xx, yy}]]++;
			Q.emplace(xx, yy, t + 1);
		}
	}

	cout << -1;

}