#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1'000'000'007;

vector<ll> S = { 0 };
void bck(ll now, int dig) {
	S.push_back(now);
	if (dig == 18)	return;
	for (int i = now % 10; i < 10; i++)	bck(now * 10 + i, dig + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 1; i <= 9; i++)	bck(i, 1);
	sort(S.begin(), S.end());

	vector<ll> V = { 0 };
	for (int i = 1; i < S.size(); i++) {
		ll res = (V[i - 1] + (((S[i] - S[i - 1] - 1) % mod) * (S[i - 1] % mod)) % mod + (S[i] % mod)) % mod;
		V.push_back(res);
	}

	auto F = [&](ll x) -> ll {
		if (x < 10)	return x * (x + 1) / 2;
		int p = upper_bound(S.begin(), S.end(), x) - S.begin() - 1;
		return (V[p] + (((x - S[p]) % mod) * (S[p] % mod)) % mod) % mod;
	};

	ll T;
	for (cin >> T; T--;) {
		ll A, B;
		cin >> A >> B;
		cout << (F(B) - F(A - 1) + mod) % mod << '\n';
	}

}