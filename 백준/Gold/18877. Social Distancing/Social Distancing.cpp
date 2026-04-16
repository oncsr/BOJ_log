#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<pair<ll, ll>> I(M);
	for (auto& [a, b] : I)	cin >> a >> b;
	sort(I.begin(), I.end());
	ll s = 0, e = 1e18, m = (s + e + 1) >> 1;
	while (s < e) {
		ll g = -1e18, d = 0;
		bool poss = 1;
		for (int i = 0; i < N; i++) {
			while (d < M && g + m > I[d].second)	d++;
			if (d == M) {
				poss = 0; break;
			}
			g = max(g + m, I[d].first);
		}
		if (poss)	s = m;
		else	e = m - 1;
		m = (s + e + 1) >> 1;
	}
	cout << m;

}