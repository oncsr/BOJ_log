#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[524288]{};
int mn[524288]{};
int inf = 1e9 + 7;

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = mn[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m) upt(s, m, i, v, n * 2);
	else upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
	mn[n] = min(mn[n * 2], mn[n * 2 + 1]);
}

int findmin(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s) return inf;
	if (l <= s && e <= r) return mn[n];
	int m = (s + e) >> 1;
	return min(findmin(s, m, l, r, n * 2), findmin(m + 1, e, l, r, n * 2 + 1));
}

ll findsum(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = (s + e) >> 1;
	return findsum(s, m, l, r, n * 2) + findsum(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N;
	for (int i = 1, a; i <= N; i++) cin >> a, upt(1, N, i, a, 1);
	for (cin >> M; M--;) {
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 1) upt(1, N, a, b, 1);
		else {
			int s = 0, e = a - 1, m = (s + e) >> 1;
			while (s < e) {
				if (findmin(1, N, m + 1, e, 1) < b) s = m + 1;
				else e = m;
				m = (s + e) >> 1;
			}
			int left = m + 1;

			s = a + 1, e = N + 1, m = (s + e) >> 1;
			while (s < e) {
				if (findmin(1, N, s, m, 1) < b) e = m;
				else s = m + 1;
				m = (s + e) >> 1;
			}
			int right = m - 1;
			cout << findsum(1, N, left, right, 1) << '\n';
		}
	}

}