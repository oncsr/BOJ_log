#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, M, S, T;
	cin >> n >> M;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; i++)	cin >> A[i];
	cin >> S >> T;

	vector<vector<pair<int, int>>> G(n + 1), R(n + 1);
	for (int a, b, c; M--;) {
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		R[b].emplace_back(a, c);
	}

	vector<ll> D1(n + 1, -1), D2(n + 1, -1), DD1(n + 1, -1), DD2(n + 1, -1);
	auto dijk = [&](vector<vector<pair<int, int>>>& V, vector<ll>& D, vector<ll>& DD, int s) -> void {
		D[s] = 0, DD[s] = A[s];
		priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> Q;
		Q.emplace(0, A[s], s);
		while (!Q.empty()) {
			auto [d, t, n] = Q.top();	Q.pop();
			if (d > D[n])	continue;
			for (auto &[i, c] : V[n]) {
				if (D[i] == -1 || D[i] > d + c) {
					D[i] = d + c;
					DD[i] = min(t, A[i]);
					Q.emplace(D[i], DD[i], i);
				}
				else if (D[i] == d + c && DD[i] > min(t, A[i])) {
					DD[i] = min(t, A[i]);
				}
			}
		}
	};

	dijk(G, D1, DD1, S);
	dijk(R, D2, DD2, T);
	ll ans = -1, dist = D1[T];
	if (dist == -1)	return cout << -1, 0;
	for (int i = 1; i <= n; i++) {
		for (auto& [j, c] : G[i]) {
			if (D1[i] == -1 || D2[j] == -1)	continue;
			if (D1[i] + c + D2[j] != dist)	continue;
			if (ans == -1)	ans = DD1[i] + DD2[j];
			else	ans = min(ans, DD1[i] + DD2[j]);
		}
	}
	cout << ans;

}