#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, a = 1, b = 1, d = 1e9 + 7;
	for (cin >> n >> m; n--;) {
		a *= m, b *= m - 1;
		a %= d, b %= d;
	}
	cout << (a - b + d) % d;
}