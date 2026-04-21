#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exp(ll n, ll p, ll mod) {
	if (p == 0)	return 1;
	if (p == 1)	return n;
	ll half = exp(n, p / 2, mod);
	if (p & 1)	return half * half % mod * n % mod;
	else	return half * half % mod;
}

int main() {

	ll a, b, c;
	cin >> a >> b >> c;
	cout << exp(a, b, c) % c;

}