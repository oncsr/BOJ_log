#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll ans = 1e18, a, b, c;
	cin >> a >> b >> c;
	for (ll A = 1; A <= 2000000; A++) {
		vector<ll> V = { c / A - 1, c / A, c / A + 1 };
		for (ll B : V) {
			if (B < 1)	continue;
			ans = min(ans, abs(A - a) + abs(B - b) + abs(A * B - c));
		}
	}
	for (ll B = 1; B <= 2000000; B++) {
		vector<ll> V = { c / B - 1, c / B, c / B + 1 };
		for (ll A : V) {
			if (A < 1)	continue;
			ans = min(ans, abs(A - a) + abs(B - b) + abs(A * B - c));
		}
	}
	cout << ans;

}