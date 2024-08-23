#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll n, ll p, ll m) {
	if (p == 0)	return 1;
	if (p == 1)	return n % m;
	ll r = power(n, p >> 1, m) % m;
	if (p & 1)	return r * r % m * n % m;
	return r * r % m;
}

int main() {
	
	ll N, mod = 1e9 + 7, ans = 1;
	cin >> N;
	queue<ll> Q;
	Q.push(1);

	ll s = 1, e = 1, x = 1, tot = 0, c = 1;
	while (tot <= N) {
		ll g = 1;
		tot += (e - s + 1) * x;
		if (tot > N) {
			tot -= (e - s + 1) * x;
			break;
		}
		for (ll i = s; i <= e; i++)	g = (g * i) % mod;
		ans = (ans * power(g, x, mod)) % mod;
		if (Q.front() == x) {
			c++;
			Q.pop();
		}
		s = e + 1;
		e += c;
		x++;
		Q.push(e);
	}
	while (tot < N) {
		tot += x;
		if (tot > N) {
			tot -= x;
			break;
		}
		ans = (ans * power(s, x, mod)) % mod;
		s++;
	}
	ans = (ans * power(s, N - tot, mod)) % mod;
	cout << ans;

}