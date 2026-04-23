#include <iostream>
using namespace std;
using ll = long long;

ll tree[100001]{};
ll seg[262145]{};

int N, M, a, b;

void I(int s, int e, int n) {
	if (s == e) {
		seg[n] = tree[s];
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	I(1, N, 1);
	for (; M--;) {
		cin >> a >> b;
		cout << find(1, N, a, b, 1) << '\n';
	}
}