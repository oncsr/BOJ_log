#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, ll>>> V(N + 1);
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	Q.emplace(0, 1);
	vector<ll> D(N + 1, -1);
	vector<ll> P(N + 1);
	D[1] = 0;

	while (!Q.empty()) {
		auto [d, n] = Q.top();
		Q.pop();
		if (d > D[n])	continue;
		for (auto [i, c] : V[n]) {
			if (D[i] == -1 || D[i] > d + c) {
				D[i] = d + c;
				Q.emplace(D[i], i);
				P[i] = c;
			}
			else if (D[i] == d + c && c < P[i]) {
				P[i] = c;
			}
		}
	}

	ll ans = 0;
	for (int i = 2; i <= N; i++) {
		ll v = D[i], c = P[i];
		ans += (v - c) * 9 / 10 + c;
	}
	cout << ans;

}