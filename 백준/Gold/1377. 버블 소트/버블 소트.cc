#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second > b.second;
	return a.first > b.first;
}
int seg[2097153]{};

void upt(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] = 1;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int fnd(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return fnd(s, m, l, r, n * 2) + fnd(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ii arr[500001]{};
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i].first, arr[i].second = i;
	sort(arr + 1, arr + n + 1, cmp);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		upt(1, n, arr[i].second, 1);
		mx = max(mx, fnd(1, n, 1, arr[i].second - 1, 1));
	}
	cout << mx + 1;
}