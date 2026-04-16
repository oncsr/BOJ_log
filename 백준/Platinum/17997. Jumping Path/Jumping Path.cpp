#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int N, p[1000001]{}, a[1000001]{}, mod = 11092019;
ii seg[2097153]{};
vector<vector<int>> V(1000001), C(1000001);
int sz[1000001]{}, dep[1000001]{}, cn[1000001]{}, ci[1000001]{}, ord[1000001]{}, rev[1000001]{}, num = 0;

int dfs(int n) {
	sz[n] = 1;
	for (int i : V[n])	sz[n] += dfs(i);
	return sz[n];
}

void hld(int n, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	C[s].push_back(n);

	ord[n] = ++num;
	rev[num] = n;
	int h = -1;
	for (int i : V[n])	if (h == -1 || sz[i] > sz[h])	h = i;
	if (h != -1)	hld(h, s, d);
	for (int i : V[n])	if (i != h)	hld(i, i, d + 1);
}

ii mrg(ii a, ii b) {
	if (a.first > b.first)	return a;
	if (a.first < b.first)	return b;
	return { a.first, (a.second + b.second) % mod };
}

void upt(int s, int e, int i, int v, int c, int n) {
	if (s == e) {
		seg[n] = { v,c };
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, c, n * 2);
	else	upt(m + 1, e, i, v, c, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

ii query(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 0,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(query(s, m, l, r, n * 2), query(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	vector<pair<int, int>> arr;
	for (int i = 1; i <= N; i++)	cin >> a[i], arr.emplace_back(a[i], i);
	for (int i = 2; i <= N; i++)	cin >> p[i], V[p[i]].push_back(i);
	dfs(1);
	hld(1, 1, 0);
	
	sort(arr.begin(), arr.end());
	int ans = -1, cnt = 0;
	for (auto& [a, i] : arr) {
		int x = i;
		ii res = { 0,0 };
		while (cn[x] != 1) {
			res = mrg(res, query(1, N, ord[cn[x]], ord[x], 1));
			x = p[cn[x]];
		}
		res = mrg(res, query(1, N, 1, ord[x], 1));
		if (res == make_pair(0, 0))	res.second = 1;
		if (res.first + 1 > ans)	ans = res.first + 1, cnt = res.second;
		else if (res.first + 1 == ans)	cnt = (cnt + res.second) % mod;
		upt(1, N, ord[i], res.first + 1, res.second, 1);
	}
	cout << ans << ' ' << cnt << '\n';

}