#include <bits/stdc++.h>
using namespace std;

int N, K, D;
int seg[1048577]{};
int mod[500001]{};

void ins(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	ins(s, m, i, v, n * 2);
	else	ins(m + 1, e, i, v, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K >> D;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		int g = find(1, 500000, max(1, a - D), min(500000, a + D), 1);
		g = max(g, mod[a % K]);
		ans = max(ans, g + 1);
		ins(1, 500000, a, g + 1, 1);
		mod[a % K] = max(mod[a % K], g + 1);
	}
	cout << ans;
}