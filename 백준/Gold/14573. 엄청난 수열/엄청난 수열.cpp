#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll arr[1000003]{};
	ll D[1000003]{};
	arr[1] = 1, arr[2] = 1;
	D[1] = 1, D[2] = 1, D[3] = 2;
	ll mul = 3, g = 2;
	for (ll i = 3; i <= 1000000; i++) {
		arr[i] = (g * D[i]) % mod;
		D[i + 1] = (D[i] * mul) % mod;
		mul = (mul + g) % mod;
		g = (g * 2) % mod;
	}

	int Q;
	for (cin >> Q; Q--;) {
		ll o, a, i, j;
		cin >> o >> a >> i;
		if (o == 4) {
			cout << arr[i] * a % mod << '\n';
			continue;
		}
		cin >> j;
		if (i > j)	swap(i, j);
		if (o == 1) {
			cout << arr[i] * a % mod << '\n';
			continue;
		}
		if (o == 2) {
			ll cnt = 0;
			while (a % 2 == 0) {
				a >>= 1;
				cnt++;
			}
			if (j <= 2)	cout << cnt << '\n';
			else	cout << cnt + j - 1 << '\n';
			continue;
		}
		ll G = ((D[j + 1] - D[i] + mod) % mod * a % mod) % mod;
		if (i == 1)	cout << (G + a) % mod << '\n';
		else	cout << G << '\n';
	}
}