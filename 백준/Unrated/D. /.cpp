#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll ans = 0, mod = 1e9 + 7, G = 1, c = 0;
	int L, R;
	cin >> L >> R;
	for (int i = 1; i <= R; i++) {
		if (L <= i && i <= R) {
			if (i <= 2)	ans++;
			else	ans = (ans + G) % mod;
		}
		if (!(i & 1))	G = G * 26 % mod;
	}
	if ((L == 1 && R == 1) || (L == 2))	cout << "H\n";
	else	cout << "A\n";
	cout << ans;
}