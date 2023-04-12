#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ii = pair<int, int>;

vector<ll> value;
ll idx[600004]{};
ll rev[600004]{};

ll seg[2097153]{};
ll lazy[2097153]{};
ii none = { 0,0 };
int N;

struct query {
	int op;
	ll l, r;
};
query Q[100000]{};

void prop(int s, int e, int n) {
	if (lazy[n]) {
		if (lazy[n] == 1)	seg[n] = e - s + 1;
		else if (lazy[n] == 2)	seg[n] = 0;
		else if (lazy[n] == 3)	seg[n] = e - s + 1 - seg[n];
		if (s != e) {
			if (lazy[n] == 3) {
				lazy[n * 2] = 3 - lazy[n * 2];
				lazy[n * 2 + 1] = 3 - lazy[n * 2 + 1];
			}
			else {
				lazy[n * 2] = lazy[n * 2 + 1] = lazy[n];
			}
		}
		lazy[n] = 0;
		return;
	}
}

void Q1(int s, int e, int l, int r, int v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (v == 1)	seg[n] = e - s + 1;
		else	seg[n] = 0;
		if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = v;
		return;
	}
	int m = (s + e) / 2;
	Q1(s, m, l, r, v, n * 2);	Q1(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void Q2(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] = e - s + 1 - seg[n];
		if (s != e) {
			lazy[n * 2] = 3 - lazy[n * 2];
			lazy[n * 2 + 1] = 3 - lazy[n * 2 + 1];
		}
		return;
	}
	int m = (s + e) / 2;
	Q2(s, m, l, r, n * 2);	Q2(m + 1, e, l, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int n) {
	if (s == e)	return s;
	prop(s, e, n);
	int m = (s + e) / 2;
	prop(s, m, n * 2);
	if (seg[n * 2] == m - s + 1)	return find(m + 1, e, n * 2 + 1);
	return find(s, m, n * 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	int cnt1 = 0;
	for (int i = 0; i < N; i++) {
		int o;
		ll a, b;
		cin >> o >> a >> b;
		Q[i] = { o,a,b };
		value.push_back(a);
		value.push_back(b);
		if (a - 1 > 0)	value.push_back(a - 1);
		value.push_back(a + 1);
		if (b - 1 > 0)	value.push_back(b - 1);
		value.push_back(b + 1);
	}
	value.push_back(1);
	sort(value.begin(), value.end());
	int id = 0;
	ll temp = -1;
	for (int i = 0; i < value.size(); i++) {
		if (temp == value[i])	idx[i] = id;
		else	idx[i] = ++id;
		temp = value[i];
		rev[id] = i;
	}
	for (int i = 0; i < N; i++) {
		int o = Q[i].op;
		ll L = idx[lower_bound(value.begin(), value.end(), Q[i].l) - value.begin()];
		ll R = idx[lower_bound(value.begin(), value.end(), Q[i].r) - value.begin()];
		if (o == 3)	Q2(1, id, L, R, 1);
		else	Q1(1, id, L, R, o, 1);
		cout << value[rev[find(1, id, 1)]] << '\n';
	}

}