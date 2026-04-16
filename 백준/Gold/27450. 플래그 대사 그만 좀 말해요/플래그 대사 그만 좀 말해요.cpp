#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	vector<ll> P(N), T(N), M(N);
	for (ll& i : P)	cin >> i;
	for (ll& i : T)	cin >> i;

	ll s = 0, a = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		a -= s;
		s -= M[i];
		if (P[i] + a >= T[i])	continue;
		ll c = (T[i] - P[i] - a - 1) / K + 1;
		ans += c;
		a += c * K;
		s += c;
		if (i + K < N)	M[i + K] += c;
	}
	cout << ans;

}