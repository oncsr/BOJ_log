#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[262145][12]{}, arr[100001]{}, N;
ll mod = 1e9 + 7;

void upt(int s, int e, int i, int k, ll v, int n) {
	if (s == e) {
		seg[n][k] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, k, v, n << 1);
	else	upt(m + 1, e, i, k, v, (n << 1) + 1);
	seg[n][k] = (seg[n << 1][k] + seg[(n << 1) + 1][k]) % mod;
}

ll find(int s, int e, int l, int r, int k, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n][k];
	int m = (s + e) >> 1;
	return (find(s, m, l, r, k, n << 1) + find(m + 1, e, l, r, k, (n << 1) + 1)) % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	vector<vector<int>> id(N + 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		id[a].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (id[i].empty())	continue;

		// idx, k, val
		vector<tuple<int, int, ll>> update;
		for (int j : id[i]) {
			update.emplace_back(j, 1, 1);
			for (int k = 2; k <= 11; k++)
				update.emplace_back(j, k, find(1, N, 1, j - 1, k - 1, 1));
		}
		for (auto [id, j, g] : update)	upt(1, N, id, j, g, 1);
	}

	cout << seg[1][11];

}