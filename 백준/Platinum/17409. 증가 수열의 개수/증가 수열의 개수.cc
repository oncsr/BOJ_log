#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll seg[262145][11]{};
int n, a, k;
ll mod = 1000000007;


ll find(int s, int e, int l, int r, int k, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n][k];
	int m = (s + e) / 2;
	return (find(s, m, l, r, k, n * 2) + find(m + 1, e, l, r, k, n * 2 + 1)) % mod;
}

void query(int s, int e, int i, ll v, int k, int n) {
	if (s == e) {
		seg[n][k] = v;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, v, k, n * 2);
	else	query(m + 1, e, i, v, k, n * 2 + 1);
	seg[n][k] = (seg[n * 2][k] + seg[n * 2 + 1][k]) % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ll g = 0;
		for (int j = 1; j < k; j++) {
			g = find(1, n, 1, a, j, 1) - g;
			query(1, n, a, g, j + 1, 1);
		}
		query(1, n, a, 1, 1, 1);
	}
	cout << find(1, n, 1, n, k, 1) % mod;
}