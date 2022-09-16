#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	ll c = max(a, b);
	ll d = min(a, b);
	a = c, b = d;
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ll N;
	cin >> N;
	int len = 0;
	ll temp = N;
	while (temp > 9) {
		temp /= 10;
		len++;
	}
	ll c = 1;
	temp = N;
	for (ll i = pow(10, len); i >= 1; i /= 10) {
		ll a = temp / i;
		if (a == 0)
			continue;
		c = lcm(a, c);
		temp -= i * a;
	}
	ll t;
	bool br = false;
	int p = 1;
	if (N % c == 0)
		cout << N << '\n';
	else {
		for (ll i = N * 10; !br; i *= 10, p++) {
			for (int j = 0; j < pow(10, p); j++) {
				t = i + j;
				if (t % c == 0) {
					br = true;
					break;
				}
			}
		}
		cout << t << '\n';
	}
}