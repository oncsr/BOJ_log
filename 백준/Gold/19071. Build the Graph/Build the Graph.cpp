#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m;
	cin >> n >> m;
	if (n == 1) { cout << 0; return 0; }
	if (n == 2) { cout << 2; return 0; }
	if (m <= n - 1) {
		ll e = n - 1 - m;
		cout << 2 * m * m + 2 * n * ((n * (n - 1)) / 2 - (n - 1 - e) * (n - e) / 2);
		return 0;
	}
	ll S = 2 * (n - 1) * (n - 1);
	m -= n - 1;
	ll need = min(m, (n - 1) * (n - 2) / 2);
	cout << S - need * 2;
}