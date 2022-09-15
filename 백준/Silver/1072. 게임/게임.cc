#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
	ll x, y;
	cin >> x >> y;
	ll z = y * 100 / x;
	if (z >= 99)
		cout << -1 << '\n';
	else {
		ll high = (z + 1) * x - 100 * y;
		ll low = 99 - z;
		double val = (double)high / (double)low;
		cout << (ll)ceil(val) << '\n';
	}
}