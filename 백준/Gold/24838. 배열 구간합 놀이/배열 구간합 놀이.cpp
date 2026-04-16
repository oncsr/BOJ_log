#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll fac[50001]{ 1 }, mod = 1e9 + 7;
	for (int i = 1; i <= 50000; i++)	fac[i] = fac[i - 1] * i % mod;

	int T;
	for (cin >> T; T--;) {
		int n, m;
		cin >> n >> m;
		vector<ll> arr(n);
		for (ll& i : arr)	cin >> i;
		sort(arr.begin(), arr.end(), greater<>());

		vector<int> s(n + 1), c(m + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			s[--x]++, s[y]--;
		}
		int v = 0;
		for (int i = 0; i < n; i++) {
			v += s[i];
			c[v]++;
		}

		ll ans = 0, x = 0, cnt = 1;
		for (int i = m; i >= 0; i--) {
			if (!c[i])	continue;
			cnt = (cnt * fac[c[i]]) % mod;
			while (c[i]--)	ans += arr[x++] * i;
		}
		cout << ans << ' ' << cnt << '\n';
	}

}