#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> V(n + 1);
	for (; m--;) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	ll ans = 0, mod = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		ll s = V[i].size();
		if (s < 3)	continue;
		ans += s * (s - 1) * (s - 2) / 6;
		ans %= mod;
	}
	cout << ans;

}