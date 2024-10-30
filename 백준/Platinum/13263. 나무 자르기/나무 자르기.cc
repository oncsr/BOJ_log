#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	vector<ll> A(N), B(N);
	for (ll& i : A)	cin >> i;
	for (ll& i : B)	cin >> i;

	auto cross = [](pair<__int128, __int128> a, pair<__int128, __int128> b, pair<__int128, __int128> c) -> bool {
		auto [ax, ay] = a;
		auto [bx, by] = b;
		auto [cx, cy] = c;
		return (ay - by) * (cx - bx) <= (by - cy) * (bx - ax);
	};

	vector<pair<ll, ll>> V = { make_pair(B[0],0) };
	vector<ll> P = { LLONG_MIN };
	ll v = 0;
	for (ll i = 1; i < N; i++) {
		ll x = A[i], d = B[i];
		
		int s = 0, e = P.size() - 1, m = (s + e + 1) >> 1;
		while (s < e) {
			if (x >= P[m])	s = m;
			else	e = m - 1;
			m = (s + e + 1) >> 1;
		}
		v = V[m].first * x + V[m].second;

		while (V.size() > 1 && cross(make_pair(d, v), V.back(), V[V.size() - 2]))	V.pop_back(), P.pop_back();
		auto [a, b] = V.back();
		V.emplace_back(d, v);
		ll p = (v - b) / (a - d);
		if ((v - b) % (a - d))	p++;
		P.push_back(p);
	}
	cout << v;

}