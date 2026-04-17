#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[200001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	iota(root, root + N + 1, 0);
	vector<tuple<ll, ll, int, int>> E;
	for (int i = 0; i < Q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		E.emplace_back(c, d, a, b);
	}

	sort(E.begin(), E.end());
	ll cost = 0, time = 0, cnt = 0;
	for (auto [c, t, a, b] : E) {
		int x = find(a), y = find(b);
		if (x == y)	continue;
		cnt++;
		cost += c;
		time = max(time, t);
		root[x] = y;
	}
	if (cnt != N - 1)	cout << -1;
	else	cout << time << ' ' << cost;

}