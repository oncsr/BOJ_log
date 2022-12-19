#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll seg[1048577]{};

void query(int s, int e, int i, int n) {
	if (s == e) {
		seg[n]++;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, n * 2);
	else	query(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b;
	cin >> n;
	vector<vector<int> > Y(400001);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a += 200000, b += 200000;
		Y[b].push_back(a);
	}
	ll ans = 0;
	for (int i = 400000; i >= 0; i--) {
		if (Y[i].empty())	continue;
		for (int now : Y[i]) {
			ll left = find(0, 400000, 0, now - 1, 1);
			ll right = find(0, 400000, now + 1, 400000, 1);
			ans += left * right;
			ans %= 1000000007;
		}
		for (int now : Y[i])	query(0, 400000, now, 1);
	}
	cout << ans;
}