#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ll N, K;
		cin >> N >> K;
		map<int, vector<ll>> V;
		V[0].push_back(0);
		vector<int> C(N + 1);
		for (int i = 1; i <= N; i++)	cin >> C[i];
		ll s = 0, j = 0;
		for (int i = 1; i <= N; i++) {
			ll a;
			cin >> a;
			j += C[i] == 1 ? 1 : -1;
			s += C[i] == 1 ? a : -a;
			V[j].push_back(s);
		}
		ll ans = 0;
		for (auto [i, I] : V) {
			if (I.size() < 2)	continue;
			sort(I.begin(), I.end());
			int l = 0;
			for (int r = 1; r < I.size(); r++) {
				while (l < r && I[r] - I[l] > K)	l++;
				ans += (ll(r) - l);
			}
		}
		cout << ans << '\n';

	}

}