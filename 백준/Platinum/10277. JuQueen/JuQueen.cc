#include <iostream>
using namespace std;
using ii = pair<int, int>;

// boj 10277

ii seg[16777217]{};
int lazy[16777217]{};
int C, N, O, a, b, c, temp;
string o;

ii merge(ii a, ii b) {
	return { min(a.first, b.first), max(a.second, b.second) };
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n].first += lazy[n];
		seg[n].second += lazy[n];
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void query(int s, int e, int l, int r, int v, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n].first += v;
		seg[n].second += v;
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	query(s, m, l, r, v, n * 2);
	query(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

ii find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return { 10001,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return merge(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int find2(int s, int e, int i, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n].first;
	int m = (s + e) / 2;
	if (i <= m)	return find2(s, m, i, n * 2);
	else return find2(m + 1, e, i, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> C >> N >> O; O--;) {
		cin >> o >> a;
		if (o == "state") {
			int T = find2(0, C - 1, a, 1);
			cout << T << '\n';
		}
		else {
			cin >> b;
			if (o == "change") {
				int T = find2(0, C - 1, a, 1);
				if (b > 0) {
					if (b + T > N)	b = N - T;
				}
				else {
					if (b + T < 0)	b = -1 * T;
				}
				cout << b << '\n';
				query(0, C - 1, a, a, b, 1);
			}
			else {
				cin >> c;
				ii T = find(0, C - 1, a, b, 1);
				if (c > 0) {
					if (c + T.second > N)	c = N - T.second;
				}
				else {
					if (c + T.first < 0)	c = -1 * T.first;
				}
				cout << c << '\n';
				query(0, C - 1, a, b, c, 1);
			}
		}
	}
}