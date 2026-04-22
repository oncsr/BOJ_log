#include <bits/stdc++.h>
using namespace std;

int root[200001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int m, n;
	for (cin >> m >> n; n; cin >> m >> n) {
		for (int i = 0; i <= 200000; i++)	root[i] = i;

		int sum = 0;
		vector<pair<int, pair<int, int>>> E;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			E.push_back({ c,{a,b} });
			sum += c;
		}

		sort(E.begin(), E.end());
		for (auto e : E) {
			int a = e.second.first, b = e.second.second, cost = e.first;
			int x = find(a), y = find(b);
			if (x == y)	continue;
			root[x] = y;
			sum -= cost;
		}
		cout << sum << '\n';
	}
}