#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
int arr[400001]{};
int seg[1048577]{};

int init(int s, int e, int n) {
	if (s == e)	return seg[n] = arr[s];
	int m = (s + e) >> 1;
	return seg[n] = init(s, m, n * 2) | init(m + 1, e, n * 2 + 1);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) | find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	init(1, N, 1);

	ll ans = 0;
	for (int i = 1; i <= N; i++) {

		int s = i, e = N, x = (s + e + 1) >> 1, y = (s + e) >> 1;
		while (s < e) {
			if (find(1, N, i, x, 1) <= K)	s = x;
			else	e = x - 1;
			x = (s + e + 1) >> 1;
		}

		s = i, e = N;
		while (s < e) {
			if (find(1, N, i, y, 1) < K)	s = y + 1;
			else	e = y;
			y = (s + e) >> 1;
		}

		if (find(1, N, i, x, 1) == K && find(1, N, i, y, 1) == K)	ans += (ll(x) - y + 1);

	}
	cout << ans;

}