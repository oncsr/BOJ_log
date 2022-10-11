#include <iostream>
using namespace std;
using ll = long long;
using pp = pair<ll, ll>;

const ll mod = 1000000007;
int tree[100001]{};
ll seg[262145]{};
pp lazy[262145]{};
int N, M, o, x, y, v;

void lazy_init(int s, int e, int n) {
	lazy[n].first = 1;
	if (s == e)	return;
	int m = (s + e) / 2;
	lazy_init(s, m, n * 2);	lazy_init(m + 1, e, n * 2 + 1);
}

void prop(int s, int e, int n) {
	if (lazy[n].first != 1 || lazy[n].second) {
		ll val1 = lazy[n].first;
		ll val2 = lazy[n].second;
		seg[n] = (val1 * seg[n] % mod + val2 * ((ll)e - s + 1) % mod) % mod;
		if (s != e) {
			lazy[n * 2].first = (lazy[n * 2].first * val1) % mod;
			lazy[n * 2].second = (lazy[n * 2].second * val1 % mod + val2 % mod) % mod;
			lazy[n * 2 + 1].first = (lazy[n * 2 + 1].first * val1) % mod;
			lazy[n * 2 + 1].second = (lazy[n * 2 + 1].second * val1 % mod + val2 % mod) % mod;
		}
		lazy[n] = { 1,0 };
	}
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = tree[s];
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
}

ll find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return (find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1)) % mod;
}

void upt(int s, int e, int l, int r, int op, ll val, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (op == 1) {
			seg[n] = (seg[n] + ((ll)e - s + 1) * val % mod) % mod;
			if (s != e) {
				lazy[n * 2].second += val;
				lazy[n * 2 + 1].second += val;
			}
		}
		else if (op == 2) {
			seg[n] = (seg[n] * val) % mod;
			if (s != e) {
				lazy[n * 2].first = lazy[n * 2].first * val % mod;
				lazy[n * 2].second = lazy[n * 2].second * val % mod;
				lazy[n * 2 + 1].first = lazy[n * 2 + 1].first * val % mod;
				lazy[n * 2 + 1].second = lazy[n * 2 + 1].second * val % mod;
			}
		}
		else {
			seg[n] = (val * ((ll)e - s + 1)) % mod;
			if (s != e) {
				lazy[n * 2] = { 0,val };
				lazy[n * 2 + 1] = { 0,val };
			}
		}
		return;
	}
	int m = (s + e) / 2;
	upt(s, m, l, r, op, val, n * 2);	upt(m + 1, e, l, r, op, val, n * 2 + 1);
	seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> tree[i];
	init(1, N, 1);	lazy_init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> o >> x >> y;
		if (o == 4)	cout << find(1, N, x, y, 1) << '\n';
		else {
			cin >> v;
			upt(1, N, x, y, o, v, 1);
		}
	}
}