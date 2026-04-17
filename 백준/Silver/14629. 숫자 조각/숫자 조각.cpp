#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, mn = 1e18, ans;
void recur(ll now, ll g, ll state) {
	if (state) {
		ll v = abs(now - N);
		if (v < mn || (v == mn && now < N))	mn = v, ans = now;
	}
	for (int i = 0; i < 10; i++) {
		if (state & (1LL << i))	continue;
		recur(now + g * i, g * 10, state | (1LL << i));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	recur(0, 1, 0);
	cout << ans;

}