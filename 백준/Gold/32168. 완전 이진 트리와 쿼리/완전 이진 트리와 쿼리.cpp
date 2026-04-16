#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, R = 1;

ll F(ll n) { return n * (n + 1) / 2; }

ll S(ll s, ll e) {
	if (N < s)	return 0;
	return S(s << 1, (e << 1) | 1) + F(min(e, N)) - F(s - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (cin >> N >> M; M--;) {
		ll o, v;
		cin >> o >> v;
		if (o == 1) { R = v; continue; }
		
		ll t = R, p = -1;
		bool isv = 0;
		while (t) {
			if (t == v) { isv = 1; break; }
			p = t;
			t >>= 1;
		}
		if (isv) {
			if (p == -1)	cout << S(1, 1) << '\n';
			else	cout << S(1, 1) - S(p, p) << '\n';
		}
		else	cout << S(v, v) << '\n';
	}

}