#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int seg[262145]{};

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
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

	int N, M, T;
	cin >> N >> M >> T;
	vector<pair<int, int>> arr;
	vector<int> X;
	for (int i = 0, a, b; i < T; i++) {
		cin >> a >> b;
		if (a <= N && b <= M)	arr.emplace_back(a, b), X.push_back(a);
	}
	sort(X.begin(), X.end());
	
	map<int, int> ch;
	int c = 1;
	for (int i : X)	if (!ch[i])	ch[i] = c++;
	
	sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	});
	int ans = 0;
	for (auto& [a, b] : arr) {
		int x = ch[a];
		int v = find(1, c, 1, x, 1);
		ans = max(ans, v + 1);
		upt(1, c, x, v + 1, 1);
	}

	cout << ans;

}