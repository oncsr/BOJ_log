#include <iostream>
using namespace std;
using ll = long long;

ll fac(ll n, ll k) {
	if (k <= 1)	return n;
	return k * fac(n, k - 1);
}

int main() {
	ll n;
	cin >> n;
	cout << fac(1, n);
}