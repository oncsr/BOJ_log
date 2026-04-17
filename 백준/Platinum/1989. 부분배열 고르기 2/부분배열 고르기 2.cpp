#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, arr[100001]{};
int L[262145]{}, R[262145]{};

void init(int s, int e, int n) {
	if (s == e) {
		L[n] = 1e9, R[n] = 0;
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	L[n] = min(L[n * 2], L[n * 2 + 1]);
	R[n] = max(R[n * 2], R[n * 2 + 1]);
}

void upt(int s, int e, int i, int n) {
	if (s == e) {
		L[n] = R[n] = i;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	L[n] = min(L[n * 2], L[n * 2 + 1]);
	R[n] = max(R[n * 2], R[n * 2 + 1]);
}

pair<int, int> find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s) return { 1e9, 0 };
	if (l <= s && e <= r)	return { L[n], R[n] };
	int m = (s + e) >> 1;
	auto le = find(s, m, l, r, n * 2);
	auto ri = find(m + 1, e, l, r, n * 2 + 1);
	return { min(le.first, ri.first), max(le.second, ri.second) };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	vector<pair<ll, int>> info;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		info.emplace_back(arr[i], i);
		arr[i] += arr[i - 1];
	}
	init(1, N, 1);
	sort(info.begin(), info.end());
	ll ans = 0, ra = 1, rb = N;
	for (auto [a, i] : info) {
		int lo = find(1, N, 1, i, 1).second;
		int hi = find(1, N, i, N, 1).first;
		if (hi > N)	hi = N;
		else	hi--;

		ll now = a * (arr[hi] - arr[lo]);
		if (now > ans) {
			ans = now;
			ra = lo + 1, rb = hi;
		}
		upt(1, N, i, 1);
	}
	cout << ans << '\n' << ra << ' ' << rb;

}