#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	ll ans = N, p = N - 1;
	for (ll i = 2; i * i <= N - 1; i++) {
		ll j = (N - 1) / i;
		ans += (i - 1) * (p - j);
		p = j;
	}
	for (; p > 0; ans += (N - 1) / (p--));
	cout << ans;

}