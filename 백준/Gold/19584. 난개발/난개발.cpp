#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, y[200001]{};
	cin >> n >> m;
	for (int i = 1, a, b; i <= n; i++) cin >> a >> b, y[i] = b;

	vector<pair<int, ll>> V;
	for (int a,b,c; m--;) {
		cin >> a >> b >> c;
		int p = y[a], q = y[b];
		if (p > q) swap(p, q);
		V.emplace_back(p, c);
		V.emplace_back(q + 1, -c);
	}
	sort(V.begin(), V.end());
	int idx = 0;
	ll ans = 0, cur = 0;
	while (idx < V.size()) {
		int pos = V[idx].first;
		while (idx < V.size() && pos == V[idx].first)	cur += V[idx++].second;
		ans = max(ans, cur);
	}
	cout << ans;

}