#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll W, H, L1, L2, ans = 0;
	cin >> W >> H >> L1 >> L2;
	if (L1 == 1)	ans += (W + 1) * H + W * (H + 1);
	for (ll a = 1; a <= W; a++) {
		for (ll b = 1; b <= H; b++) {
			if (gcd(a, b) > 1 && a > 1 && b > 1)	continue;
			if (L1 * L1 <= a * a + b * b && a * a + b * b <= L2 * L2) {
				ans += (W - a + 1) * (H - b + 1) * 2;
			}
		}
	}
	cout << ans;
}