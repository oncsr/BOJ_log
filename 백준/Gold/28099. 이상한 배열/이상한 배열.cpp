#include <bits/stdc++.h>
using namespace std;

vector<int> seg;
vector<int> arr;

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
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
	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		seg = vector<int>(4 * N);
		arr = vector<int>(N + 1);
		vector<vector<int>> idx(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			if (idx[arr[i]].size() > 1)	idx[arr[i]].pop_back();
			idx[arr[i]].push_back(i);
		}
		init(1, N, 1);
		bool ans = 1;
		for (int i = 1; i <= N; i++) {
			if (idx[i].size() <= 1)	continue;
			int mx = find(1, N, idx[i][0], idx[i][1], 1);
			ans &= (mx <= i);
		}
		cout << (ans ? "Yes" : "No") << '\n';
	}
}