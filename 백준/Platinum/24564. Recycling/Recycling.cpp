#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, r[100001]{}, id = 0;
	ll c[100001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	c[i] = 1;
	function<int(int)> F = [&](int x) -> int { return x == r[x] ? x : r[x] = F(r[x]); };
	vector<pair<ll, int>> arr(N);

	for (auto& [a, b] : arr)	cin >> a, b = ++id;
	sort(arr.begin(), arr.end(), greater<>());

	ll ans = -1, s = 0, e = 0;
	for (auto& [a, b] : arr) {
		ll sz = 1;
		r[b] = b;
		int ss = b, ee = b;
		if (b != 1 && r[b - 1]) {
			int x = F(b - 1);
			sz += c[x];
			ss -= c[x];
			c[b] += c[x];
			r[x] = b;
		}
		if (b != N && r[b + 1]) {
			int x = F(b + 1);
			sz += c[x];
			ee += c[x];
			c[b] += c[x];
			r[x] = b;
		}
		if ((sz * a > ans) || (ans == sz * a && ss < s))	ans = sz * a, s = ss, e = ee;
		ans = max(ans, sz * a);
	}
	cout << s << ' ' << e << ' ' << ans;

}