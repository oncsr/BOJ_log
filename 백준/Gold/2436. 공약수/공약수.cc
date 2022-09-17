#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	ll c = max(a, b);
	ll d = min(a, b);
	if (c % d == 0)
		return d;
	else
		return gcd(d, c % d);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll c = sqrt(a * b);
	ll i;
	for (i = c; ; i--) {
		if ((a * b) % i == 0)
			if (gcd(i, a * b / i) == gcd(a, b))
				break;
	}
	cout << i << ' ' << a * b / i << '\n';
}