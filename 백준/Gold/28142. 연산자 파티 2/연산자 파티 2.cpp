#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N, P = 1000000007;

ll pr(ll p) {
	if (p == 0)	return 1;
	if (p == 1)	return 2;
	ll part = pr(p / 2);
	if (p & 1)	return part * part % P * 2 % P;
	return part * part % P;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	ll X = N / 255 * 255;
	if (X % 1023 == 0)	X = ((X % P) * (pr(X) % P)) % P;
	ll i = X + 1;
	while (i <= N) {
		X = abs(X - i);
		if (i % 3 == 0)	X = ((X % P) * (i % P)) % P;
		if (i % 15 == 0)	X &= i;
		if (i % 63 == 0)	X ^= i;
		if (i % 255 == 0)	X |= i;
		if (i % 1023 == 0)	X = ((X % P) * (pr(i) % P)) % P;
		i++;
		
	}
	cout << X;
}