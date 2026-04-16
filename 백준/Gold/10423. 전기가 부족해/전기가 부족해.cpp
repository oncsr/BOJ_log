#include <bits/stdc++.h>
using namespace std;

int root[1001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, K;
	cin >> N >> M >> K;
	iota(root, root + N + 1, 0);
	int p;
	cin >> p;
	for (int i = 1; i < K; i++) {
		int a;
		cin >> a;
		int x = find(p);
		root[a] = x;
	}
	int ans = 0;
	vector<tuple<int, int, int>> E;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.emplace_back(c, a, b);
	}
	sort(E.begin(), E.end());
	for (auto& [c, a, b] : E) {
		int x = find(a), y = find(b);
		if (x == y)	continue;
		ans += c;
		root[x] = y;
	}
	cout << ans;

}