#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg(2097153);
vector<ll> arr(1000001);

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll F(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(F(s, m, l, r, n * 2), F(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int TC;
	for (cin >> TC; TC--;) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)	cin >> arr[i];
		init(1, N, 1);
		ll ans = 0;
		for (int i = 1; i < N; i++) {
			ans += max(0LL, F(1, N, i + 1, N, 1) - arr[i]);
		}
		cout << ans << '\n';
	}

}