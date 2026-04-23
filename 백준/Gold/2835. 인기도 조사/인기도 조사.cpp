#include <iostream>
using namespace std;
using ll = long long;

ll seg[262145]{};
ll lazy[262145]{};
// 2835
void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] += ((ll)e - s + 1) * lazy[n];
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void query(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] += ((ll)e - s + 1);
		if (s != e) {
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
		return;
	}
	int m = (s + e) / 2;
	query(s, m, l, r, n * 2);	query(m + 1, e, l, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	int N, Q = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d, e, f;
		char g;
		cin >> a >> g >> b >> g >> c >> g >> d >> g >> e >> g >> f;
		int L = a * 3600 + b * 60 + c, R = d * 3600 + e * 60 + f;
		if (R < L) {
			query(0, 86399, L, 86399, 1);
			query(0, 86399, 0, R, 1);
		}
		else	query(0, 86399, L, R, 1);
	}
	for (cin >> Q; Q--;) {
		int a, b, c, d, e, f;
		char g;
		cin >> a >> g >> b >> g >> c >> g >> d >> g >> e >> g >> f;
		int L = a * 3600 + b * 60 + c, R = d * 3600 + e * 60 + f;
		ll s, p;
		if (R < L) {
			s = find(0, 86399, L, 86399, 1);
			s += find(0, 86399, 0, R, 1);
			p = (ll)R - L + 86401;
		}
		else {
			s = find(0, 86399, L, R, 1);
			p = (ll)R - L + 1;
		}
		cout << (double)s / p << '\n';
	}
	cout.unsetf(ios::fixed);
}