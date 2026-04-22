#include <iostream>
using namespace std;
using ll = long long;

int N, M, K;
ll arr[1000001]{};
ll seg[2097153]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void change(int s, int e, int i, ll v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	change(s, m, i, v, n * 2);
	else	change(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)	change(1, N, b, c, 1);
		else	cout << find(1, N, b, c, 1) << '\n';
	}
}