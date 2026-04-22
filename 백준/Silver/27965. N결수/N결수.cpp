#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 0;
		return 0;
	}
	ll temp = 1;
	for (ll i = 2; i <= n; i++) {
		ll g = 1, t = log10(i) + 1;
		while (t--)	g *= 10;
		temp = temp * g + i;
		if (temp < k)	continue;
		temp -= (temp / k) * k;
	}
	cout << temp % k;
}