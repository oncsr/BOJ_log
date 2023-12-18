#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll arr[1000001]{}, N, ans = 0;
	cin >> N;
	for (ll i = 0; i < N; i++) {
		ll a;
		cin >> a;
		if (a == 1) { arr[1] = 1; continue; }
		ll mx = arr[1];
		for (ll j = 2; j * j <= a; j++) {
			if (a % j)	continue;
			mx = max(mx, arr[j]);
			mx = max(mx, arr[a / j]);
		}
		arr[a] = max(arr[a], mx + 1);
		ans = max(ans, arr[a]);
	}
	cout << ans;

}