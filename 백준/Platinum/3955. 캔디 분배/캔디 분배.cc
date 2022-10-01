#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b > a)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		if (gcd(a, b) != 1)	cout << "IMPOSSIBLE\n";
		else {
			if (a == 1) {
				if (b == 1)	cout << "2\n";
				else	cout << "1\n";
			}
			else if (b == 1) {
				if (a != 1e+9)	cout << a + 1 << '\n';
				else	cout << "IMPOSSIBLE\n";
			}
			else {
				ll r0 = a, r1 = b, s0 = 1, s1 = 0, t0 = 0, t1 = 1;
				ll temp = 0, q = 0;
				while (r1) {
					q = r0 / r1;
					temp = r0;
					r0 = r1;
					r1 = temp - r1 * q;
					temp = s0;
					s0 = s1;
					s1 = temp - s1 * q;
					temp = t0;
					t0 = t1;
					t1 = temp - t1 * q;
				}
				if (t0 < 0)	t0 += a;
				if (t0 > 1e+9)	cout << "IMPOSSIBLE\n";
				else	cout << t0 << '\n';
			}
		}
	}
}