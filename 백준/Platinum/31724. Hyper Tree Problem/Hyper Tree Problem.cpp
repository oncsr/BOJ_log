#include <bits/stdc++.h>
using namespace std;

int root[6000021]{};
int cnt[6000021]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	iota(root, root + (N+1) * 20 + 1, 0);
	fill(cnt, cnt + (N+1) * 20 + 1, 1);
	vector<tuple<int, int, int>> edge(N - 1);
	for (auto& [a, b, c] : edge) {
		cin >> a >> b >> c;
		for (int i = 0; i < 20; i++) {
			if (c & (1 << i))	continue;
			int x = find(a * 20 + i + 1), y = find(b * 20 + i + 1);
			root[x] = y;
			cnt[y] += cnt[x];
		}
	}

	for (; Q--;) {
		int o;
		cin >> o;
		if (o == 1) {
			int e, v;
			cin >> e >> v;
			e--;
			auto& [a, b, c] = edge[e];
			for (int i = 0; i < 20; i++) {
				if ((c & (1 << i)) && !((c & v) & (1 << i))) {
					int x = find(a * 20 + i + 1), y = find(b * 20 + i + 1);
					root[x] = y;
					cnt[y] += cnt[x];
				}
			}
			c &= v;
		}
		else {
			int n;
			cin >> n;
			long long res = 0;
			for (int i = 0; i < 20; i++) {
				res += (1LL << i) * ((long long)N - cnt[find(n * 20 + i + 1)]);
			}
			cout << res << '\n';
		}
	}

}