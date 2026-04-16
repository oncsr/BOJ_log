#include <bits/stdc++.h>
using namespace std;

int ex[1048577]{}, N, idx[300001]{};

void init(int s, int e, int n) {
	if (s == e) {
		ex[n] = 1;
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	ex[n] = ex[n * 2] + ex[n * 2 + 1];
}

void upt(int s, int e, int i, int n) {
	if (s == e) {
		ex[n] = 0;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	ex[n] = ex[n * 2] + ex[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return ex[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int find_idx(int s, int e, int v, int n) {
	if (s == e)	return s;
	int m = (s + e) >> 1;
	if (v <= ex[n * 2])	return find_idx(s, m, v, n * 2);
	return find_idx(m + 1, e, v - ex[n * 2], n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	init(1, N, 1);
	upt(1, N, 1, 1);
	int ans[300001] = { 0,1 };
	idx[1] = 1;
	for (int i = 1; i < N; i++) {
		int p, x;
		cin >> p >> x;
		p = idx[p];
		x += find(1, N, 1, p, 1);
		x %= (N - i);
		if (!x)	x = N - i;
		int k = find_idx(1, N, x, 1);
		upt(1, N, k, 1);
		idx[i + 1] = k;
		ans[k] = i + 1;
	}
	for (int i = 1; i <= N; i++)	cout << ans[i] << '\n';

}