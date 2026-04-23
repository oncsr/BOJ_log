#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b > a)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, b, x, y;
	cin >> n >> b;
	ll up = -1 * b * n, down = 0;
	for (; n--;) {
		cin >> x >> y;
		down += x, up += y;
	}
	if (down == 0)	cout << "EZPZ";
	else if (up == 0)	cout << 0;
	else {
		ll g = gcd(abs(up), abs(down));
		up /= g, down /= g;
		if (up < 0 && down < 0)	up = abs(up), down = abs(down);
		else if (up < 0 || down < 0)	down = abs(down), up = -1 * abs(up);
		if (down == 1)	cout << up;
		else	cout << up << '/' << down;
	}
}