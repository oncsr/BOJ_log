#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		int N, M, P, Q;
		cin >> N >> M >> P >> Q;
		vector<tuple<int, int, int>> edge(M);
		for (auto& [c, a, b] : edge)	cin >> a >> b >> c;

		sort(edge.begin(), edge.end());

		vector<int> root(N + 1);
		iota(root.begin(), root.end(), 0);

		function<int(int)> find = [&](int x) -> int {
			if (x == root[x])	return x;
			return root[x] = find(root[x]);
		};

		int mst = 0;
		for (auto& [c, a, b] : edge) {
			int x = find(a), y = find(b);
			if (x == y)	continue;
			root[x] = y;
			mst += c;
		}

		int mst2 = 0;
		iota(root.begin(), root.end(), 0);
		for (auto& [c, a, b] : edge) {
			if ((a == P && b == Q) || (a == Q && b == P)) {
				root[a] = b;
				mst2 = c;
				break;
			}
		}
		for (auto& [c, a, b] : edge) {
			int x = find(a), y = find(b);
			if (x == y)	continue;
			root[x] = y;
			mst2 += c;
		}

		cout << (mst == mst2 ? "YES\n" : "NO\n");

	}

}