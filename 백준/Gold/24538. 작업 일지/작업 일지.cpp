#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll seg[4194305]{};
pl lazy[4194305]{};
ll arr[1000001]{};

void prop(int s, int e, int n) {
	if (lazy[n].first || lazy[n].second) {
		ll len = (ll)e - s + 1;
		int m = (s + e) >> 1;
		seg[n] += lazy[n].first * len + s * (len - 1) * len / 2;
		if (s != e) {
			lazy[n * 2].first += lazy[n].first;
			lazy[n * 2].second += lazy[n].second;
			lazy[n * 2 + 1].first += lazy[n].first + lazy[n].second * ((ll)m - s + 1);
			lazy[n * 2 + 1].second += lazy[n].second;
		}
		else {
			arr[s] = seg[n];
		}
		lazy[n] = { 0,0 };
		return;
	}
}

void query(int s, int e, int l, int r, ll v, int n) {
	if (l > r || l > e || r < s)	return;
	prop(s, e, n);
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		ll len = (ll)e - s + 1;
		seg[n] += len * v + (len - 1) * len / 2;
		if (s != e) {
			lazy[n * 2].first += v;
			lazy[n * 2].second++;
			lazy[n * 2 + 1].first += v + m - s + 1;
			lazy[n * 2 + 1].second++;
		}
		else {
			arr[s] = seg[n];
		}
		return;
	}
	query(s, m, l, r, v, n * 2);
	query(m + 1, e, l, r, max((ll)m + 2 - l, 1LL), n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void cle(int s, int e, int n) {
	prop(s, e, n);
	if (s == e) {
		arr[s] = seg[n];
		return;
	}
	int m = (s + e) >> 1;
	cle(s, m, n * 2);
	cle(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		query(1, K, a, b, 1, 1);
	}
	cle(1, K, 1);
	for (int i = 1; i <= K; i++)	cout << arr[i] << ' ';
	
}