#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * 2; j <= 1000000; j += i)
				e[j] = 1;

	vector<ll> f(1000001, 1);
	for (int i = 2; i <= 1000000; i++) {
		if (!e[i]) {
			f[i] = (ll)i + 1;
			continue;
		}
		ll g = i, k = 2;
		while (g > 1) {
			if (k * k > g)	break;
			if (e[k]) {
				k++;
				continue;
			}
			ll t = 1;
			while (g % k == 0) {
				g /= k;
				t *= k;
			}
			if (g == 1) {
				f[i] *= (f[t / k] * k + 1);
			}
			else {
				f[i] *= f[t];
			}
			k++;
		}
		if (g > 1)	f[i] *= f[g];
	}
	ll g[1000001]{};
	for (int i = 1; i <= 1000000; i++)	g[i] = g[i - 1] + f[i];
	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		cout << g[N] << '\n';
	}
}