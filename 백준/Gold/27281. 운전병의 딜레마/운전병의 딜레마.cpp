#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	ll T;
	cin >> N >> M >> T;
	vector<vector<tuple<int, ll, ll>>> V(50001);
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		V[a].emplace_back(b, c, d);
		V[b].emplace_back(a, c, d);
	}

	int s = 0, e = 1e9 + 1, m = (s + e) >> 1;
	while (s < e) {

		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
		vector<ll> D(N + 1, -1);
		D[1] = 0;
		Q.emplace(0, 1);
		while (!Q.empty()) {
			auto [d, n] = Q.top();
			Q.pop();
			if (d > D[n]) continue;
			for (auto [i, c, e] : V[n]) {
				if (e > m) c += e - m;
				if (D[i] == -1 || D[i] > d + c) {
					D[i] = d + c;
					Q.emplace(d + c, i);
				}
			}
		}
		if (D[N] != -1 && D[N] <= T) e = m;
		else s = m + 1;
		m = (s + e) >> 1;

	}
	cout << (m == 1e9 + 1 ? -1 : m);

}