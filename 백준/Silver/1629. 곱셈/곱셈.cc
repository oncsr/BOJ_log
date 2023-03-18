#include <iostream>
using namespace std;
using ll = long long;

ll P(ll a, ll b, ll c) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	ll part = P(a, b / 2, c);
	if (b % 2)	return ((part * part) % c) * a % c;
	return part * part % c;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << P(a, b, c) % c;
}