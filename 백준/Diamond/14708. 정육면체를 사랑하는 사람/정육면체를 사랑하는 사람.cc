#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll K;
	cin >> K;
	ll g = pow(K, 1. / 3);
	ll mn = 9e18;
	ll A = -1, B = -1, C = -1;
	for (ll a = max(1LL, g - 2000); a <= g + 2000; a++)	for (ll b = max(1LL, g - 2000); b <= g + 2000; b++) {
		ll c = (K - 1) / (a * b) + 1;
		ll res = a * b + b * c + c * a;
		if (res < mn)	mn = res, A = a, B = b, C = c;
	}
	cout << A << ' ' << B << ' ' << C;

}