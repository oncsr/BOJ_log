#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll seg[2097153]{};

void upt(int s, int e, int i, ll v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m) upt(s, m, i, v, n * 2);
	else upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, a, b, c;
	for (cin >> N >> M; M--;) {
		cin >> a >> b >> c;
		if (a) upt(1, N, b, c, 1);
		else cout << find(1, N, min(b, c), max(b, c), 1) << '\n';
	}

}