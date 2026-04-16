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
	vector<vector<ll>> D(N + 1, vector<ll>(2, -1));
	D[1][0] = 0;
	while (!Q.empty()) {
		auto [d, n] = Q.top();
		Q.pop();
		if (d > D[n][d & 1])	continue;
		for (auto& [i, c] : V[n]) {
			ll r = d + c;
			if (D[i][r & 1] == -1 || D[i][r & 1] > r) {
				D[i][r & 1] = r;
				Q.emplace(r, i);
			}
		}
	}
	for (int i = 1; i <= N; i++)	cout << D[i][1] << ' ' << D[i][0] << '\n';

}