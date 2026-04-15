#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> res;

ll power(ll n, ll p, ll m) {
	if (p == 0)  return 1;
	if (p == 1)  return n;
	__int128 r = power(n, p >> 1, m);
	return (p & 1) ? r * r % m * n % m : r * r % m;
}

bool miller_rabin(ll n) {
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (!(n & 1))  return false;

	for (auto& a : { 2,3,5,7,11,13,17,19,23,29,31,37 }) {
		if (n == a)    return true;
		if (n % a == 0)    return false;
		bool may_prime = 0;

		
		ll T = (n - 1) >> 1;
		while (1) {
			ll v = power(a, T, n);
			if (v == n - 1) { may_prime = 1; break; }
			if (T & 1) {
				if (v == n - 1 || v == 1)  may_prime = 1;
				break;
			}
			T >>= 1;
		}

		if (n > 40 && !may_prime)  return false;
	}
	if (n <= 40) return false;
	return true;

}

void rho(ll n) {
	if (n == 1)  return;
	if (!(n & 1)) { res.push_back(2); rho(n >> 1); return; }

	if (miller_rabin(n)) { res.push_back(n); return; }

	ll c, x, y, v;
	c = rand() % 20 + 1;
	x = y = rand() % (n - 2) + 2;

	auto f = [&](ll g) {return ((__int128)g * g + c) % n; };
	do x = f(x), y = f(f(y)), v = gcd(abs(y - x), n);
	while (v == 1);

	rho(v);

	rho(n / v);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int ans = 0;
	map<ll, vector<int>> M;
	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		res = vector<ll>();
		rho(n);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		
		for (ll j : res)    M[j].push_back(i);
	}

	for (auto [a, V] : M) {
		for (int i = 0; i < V.size(); i++) {
			int g = 1;
			while (i < V.size() - 1 && V[i] + 1 == V[i + 1]) {
				g++;
				i++;
			}
			ans ^= g;
		}
	}
	cout << (ans ? "First" : "Second");

}