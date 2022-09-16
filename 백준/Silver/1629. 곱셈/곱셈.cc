#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll power(ll x, ll n, ll c) {
	if (n == 0)
		return 1;
	else {
		ll part = power(x, n / 2, c);
		ll result = part % c * part % c;
		if (n % 2 == 1)
			result = result * x % c;
		return result % c;
	}
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << power(a, b, c) % c << '\n';
}