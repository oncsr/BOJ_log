#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	const ll mod = 1e9 + 7;
	int e[10000001]{};
	for (int i = 2; i * i <= 10000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 10000000; j += i)
				if (!e[j])
					e[j] = i;

	vector<int> cnt(10000001);
	vector<int> ans(10000001);
	ans[1] = 1;
	ll val = 1;
	for (ll t = 2; t <= 10000000; t++) {
		ll num = t;
		while (e[num]) {
			cnt[e[num]]++;
			if ((cnt[e[num]] & 1) == 0)	val = val * e[num] % mod * e[num] % mod;
			num /= e[num];
		}
		if (num > 1) {
			cnt[num]++;
			if ((cnt[num] & 1) == 0)	val = val * num % mod * num % mod;
		}
		ans[t] = val;
	}

	ll N;
	for (cin >> N; N; cin >> N)	cout << ans[N] << '\n';

}