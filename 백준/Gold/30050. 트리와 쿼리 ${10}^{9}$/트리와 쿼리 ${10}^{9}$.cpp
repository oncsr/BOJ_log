#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	map<ll, ll> par;
	int Q;
	for (cin >> Q; Q--;) {
		ll o, a, b;
		cin >> o >> a >> b;
		if (o == 1) {
			par[b] = a;
			continue;
		}

		ll ans = 0;
		while (a != b) {
			if (a < b) {
				ans += b;
				if (par.find(b) == par.end())	b >>= 1;
				else	b = par[b];
			}
			else {
				ans += a;
				if (par.find(a) == par.end())	a >>= 1;
				else	a = par[a];
			}
		}
		ans += a;
		cout << ans << '\n';
		
	}

}