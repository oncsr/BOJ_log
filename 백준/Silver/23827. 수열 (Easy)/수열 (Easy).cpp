#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll mod = 1'000'000'007;

	ll N;
	cin >> N;

	ll ans = 0;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		sum += a;
		if (i == 0)	continue;
		ans += a * (sum - a);
		ans %= mod;
	}
	cout << ans;

}