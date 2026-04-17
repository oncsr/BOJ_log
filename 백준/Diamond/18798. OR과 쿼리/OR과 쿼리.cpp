#include <bits/stdc++.h>
using namespace std;

int N, K, M;
bitset<16777217> fin;
int val[250001]{};
int seg[524289]{};

void upt2(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt2(s, m, i, v, n * 2);
	else	upt2(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void upt(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return;
	if (s == e) {
		fin[n] = 1;
		int idx = (s - 1) % N + 1;
		int ord = (s - 1) / N;
		int prev = val[idx];
		val[idx] |= (1 << ord);
		if (prev != K && val[idx] == K)	upt2(1, N, idx, 1, 1);
		if (prev == K && val[idx] != K)	upt2(1, N, idx, 0, 1);
		return;
	}
	int m = (s + e) >> 1;
	if (!fin[n * 2])	upt(s, m, l, r, n * 2);
	if (!fin[n * 2 + 1])	upt(m + 1, e, l, r, n * 2 + 1);
	fin[n] = fin[n * 2] & fin[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
		if (val[i] == K)	upt2(1, N, i, 1, 1);
	}

	for (cin >> M; M--;) {
		int o, l, r, x;
		cin >> o >> l >> r;
		if (o == 1) {
			cin >> x;
			for (int i = 0; i < 30; i++) {
				if (!((1 << i) & x))	continue;
				upt(1, 30 * N, i * N + l, i * N + r, 1);
			}
		}
		else	cout << find(1, N, l, r, 1) << '\n';
	}

}