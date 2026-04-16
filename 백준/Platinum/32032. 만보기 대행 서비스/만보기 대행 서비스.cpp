#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, D;
	cin >> N >> D;
	ll mx = -2e9, mn = 2e9;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	if (mn < 0 && mx > 0) {
		ll a = mx - mn + abs(mn) + max(D, 2 * (mx - mn)) + abs(mx);
		ll b = mx - mn + abs(mn) + D + mx - mn + abs(mn);
		ll c = mx - mn + abs(mx) + max(D, 2 * (mx - mn)) + abs(mn);
		ll d = mx - mn + abs(mx) + D + mx - mn + abs(mx);
		ll e = 2 * (mx - mn) + D + min({ D, 2 * abs(mn), 2 * abs(mx) });
		cout << min({ a,b,c,d,e });
	}
	else if (mn >= 0) {
		cout << 2 * mx + D;
	}
	else {
		cout << 2 * abs(mn) + D;
	}

}