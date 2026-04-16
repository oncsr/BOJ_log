#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	auto sum = [](ll n) -> ll { return n * (n + 1) / 2; };

	ll N, M, mod = 1e9 + 7, ans = 0, prev = 0;
	cin >> N >> M;
	stack<pair<ll, ll>> S;
	for (ll i = 1; i * i <= N; i++) {
		ll s = N / i, e = N / (i + 1) + 1;
		S.emplace(s, i);
		prev = e;
		ll G = 0;
		if ((s - e) / M == 0) {
			if ((e % M) > (s % M))	G = sum(M - 1) - sum((e % M) - 1) + sum(s % M);
			else	G = sum(s % M) - sum((e % M) - 1);
		}
		else {
			G = sum(M - 1) - sum((e % M) - 1);
			e += (M - (e % M));
			G = (G + ((s - e) / M) * sum(M - 1)) % mod;
			G = (G + sum(s % M)) % mod;
		}
		ans = (ans + G % mod * i) % mod;

	}
	if (!S.empty() && prev == S.top().second)	S.pop();
	while (!S.empty()) {
		auto [a, b] = S.top();
		S.pop();
		ans = (ans + a * (b % M)) % mod;
	}
	cout << ans;

}