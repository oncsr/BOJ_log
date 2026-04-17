#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = 5'000'000'000'000'000'000;
ll cnt[262145]{};
vector<ll> mx(262145, -INF);
priority_queue<ll> arr[100001]{};
ll N, M, K;

void ins(int s, int e, int i, ll h, int n) {
	if (s == e) {
		arr[s].push(h);
		cnt[n]++;
		mx[n] = max(mx[n], h);
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	ins(s, m, i, h, n * 2);
	else	ins(m + 1, e, i, h, n * 2 + 1);
	cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
	mx[n] = max(mx[n * 2], mx[n * 2 + 1]);
}

void upt(int s, int e, int l, int r, ll h, int n) {
	if (l > r || l > e || r < s)	return;
	if (!cnt[n])	return;
	if (mx[n] <= h)	return;
	if (s == e) {
		while (!arr[s].empty() && arr[s].top() > h)	arr[s].pop();
		cnt[n] = arr[s].size();
		mx[n] = (arr[s].empty() ? -INF : arr[s].top());
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, h, n * 2);
	upt(m + 1, e, l, r, h, n * 2 + 1);
	cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
	mx[n] = max(mx[n * 2], mx[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return cnt[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	for (; M--;) {
		ll a, b, c, d, e;
		cin >> a >> b >> c >> d;
		if (a == 1)	ins(1, N, c, d - (b - 1) * K, 1);
		else if (a == 2) { cin >> e; upt(1, N, c, d, e - (b - 1) * K, 1); }
		else	cout << find(1, N, c, d, 1) << '\n';
	}

}