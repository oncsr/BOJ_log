#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[1025]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<tuple<int, int, int>> E;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		root[i] = i;
		for (int j = i + 1; j <= N; j++) {
			int a;
			cin >> a;
			E.push_back({ a, i, j });
		}
	}
	sort(E.begin(), E.end());
	vector<vector<int>> V(N + 1);
	for (auto e : E) {
		int c = get<0>(e), a = get<1>(e), b = get<2>(e);
		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		cout << V[i].size() << ' ';
		sort(V[i].begin(), V[i].end());
		for (auto j : V[i])	cout << j << ' ';
		cout << '\n';
	}
}