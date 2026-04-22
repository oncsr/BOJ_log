#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, T, P, ans = 0, tm = 0;
	priority_queue<ll> Q;
	cin >> N >> T >> P;
	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		Q.push(a);
		tm += a;
		if (tm > T) {
			tm -= Q.top();
			Q.pop();
		}
		tm += P;
		ans = max(ans, (ll)Q.size());
	}
	cout << ans;
}