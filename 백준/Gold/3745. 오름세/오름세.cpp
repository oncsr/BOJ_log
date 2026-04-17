#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> seg;

void upt(int s, int e, int i, int v, int n) {
	if (s == e) { seg[n] = v; return; }
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	while (cin >> N) {
		vector<pair<int, int>> arr(N);
		seg = vector<int>(4 * N);
		for (int i = 1; i <= N; i++)   cin >> arr[i - 1].first, arr[i - 1].second = i;
		sort(arr.begin(), arr.end(), [&](auto a, auto b) -> bool {
			if (a.first == b.first)	return a.second > b.second;
			return a.first < b.first;
		});
		for (auto [a, i] : arr)	upt(1, N, i, find(1, N, 1, i - 1, 1) + 1, 1);
		cout << seg[1] << '\n';
	}

}