#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	pair<int, int> arr[1000001]{};
	for (int i = 1; i <= n; i++)	cin >> arr[i].first, arr[i].second = i;
	sort(arr + 1, arr + n + 1);
	int ans[1000001]{};
	for (int i = 1; i <= n; i++) {
		auto [a, b] = arr[i];
		ans[b] = find(1, n, 1, b - 1, 1);
		upt(1, n, b, 1);
	}
	for (int i = 1; i <= n; i++)	cout << ans[i] << '\n';

}