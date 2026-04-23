#include <iostream>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
ll seg[2097153]{};
ll tree[1000001] = { 1,1 };
int lazy[2097153]{};

void prop(int s, int e, int n) {
	if (lazy[n]) {
		if (s == e)	seg[n] = tree[lazy[n]];
		else {
			int m = (s + e) / 2;
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n] + m + 1 - s;
		}
		lazy[n] = 0;
	}
}

void qry(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	int m = (s + e) / 2;
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (s == e)	seg[n] = tree[s - l + 1];
		else {
			lazy[n * 2] = s - l + 1;
			lazy[n * 2 + 1] = m - l + 2;
		}
		return;
	}
	qry(s, m, l, r, n * 2);	qry(m + 1, e, l, r, n * 2 + 1);
}

void print(int s, int e, int n) {
	prop(s, e, n);
	if (s == e) {
		cout << seg[n] << ' ';
		return;
	}
	int m = (s + e) / 2;
	print(s, m, n * 2);	print(m + 1, e, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, l, r;
	cin >> N >> Q;
	for (int i = 2; i <= N; i++)
		tree[i] = (tree[i - 1] + tree[i - 2]) % mod;
	for (; Q--;) {
		cin >> l >> r;
		qry(1, N, l, r, 1);
	}
	print(1, N, 1);
}