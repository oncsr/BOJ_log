#include <bits/stdc++.h>
using namespace std;

int seg[1048577]{};
int arr[400001]{};

int init(int s, int e, int n) {
	if (s == e)	return seg[n] = arr[s];
	int m = (s + e) >> 1;
	return seg[n] = min(init(s, m, n * 2), init(m + 1, e, n * 2 + 1));
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 1e9;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return min(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q, G;
	cin >> N >> Q >> G;
	for (int i = 1; i <= 2 * N; i++) {
		char a;
		cin >> a;
		arr[i] = arr[i - 1] + (a == '(' ? 1 : -1);
	}

	init(1, 2 * N, 1);
	for (; Q--;) {
		int l, r;
		cin >> l >> r;
		cout << (arr[r] - find(1, 2 * N, l, r, 1) + 1) / 2 << '\n';
	}

}