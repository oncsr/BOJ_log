#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int mod = 1'000'000'007;
ii seg[1048577]{};

ii mrg(ii a, ii b) {
	if (a.first > b.first)	return a;
	if (a.first < b.first)	return b;
	return { a.first, (a.second + b.second) % mod };
}

void upt(int s, int e, int i, int v, int c, int n) {
	if (s == e) {
		seg[n] = mrg(seg[n], { v,c % mod });
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, c, n * 2);
	else	upt(m + 1, e, i, v, c, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

ii find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 0,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	vector<int> X;
	for (auto& [y, x] : arr)	cin >> x >> y, X.push_back(x);
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	int c = 0;
	map<int, int> M;
	for (int i : X)	M[i] = ++c;
	sort(arr.begin(), arr.end());
	
	int prev = -1;
	queue<tuple<int, int, int>> Q;
	int ans = 0, cnt = 0;
	for (auto& [y, _x] : arr) {
		if (prev != y) {
			while (!Q.empty()) {
				auto [x, v, t] = Q.front(); Q.pop();
				upt(1, c, x, v, t, 1);
			}
		}
		int x = M[_x];
		ii res = find(1, c, 1, x - 1, 1);
		if (res == make_pair(0, 0))	res.second = 1;
		
		if (res.first + 1 > ans)	ans = res.first + 1, cnt = res.second;
		else if (res.first + 1 == ans)	cnt = (cnt + res.second) % mod;

		Q.emplace(x, res.first + 1, res.second);
		prev = y;
	}
	cout << ans << '\n' << cnt % mod;

}