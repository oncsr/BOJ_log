#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, B, K, Q;
	cin >> N >> M >> B >> K >> Q;
	vector<vector<pair<int, ll>>> V(N + M + B + 1);
	for (; K--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	vector<vector<ll>> D(B + 1, vector<ll>(N + M + B + 1, -1));
	for (int i = 1; i <= B; i++) {
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
		Q.emplace(0, N + M + i);
		D[i][N + M + i] = 0;
		while (!Q.empty()) {
			auto [dist, now] = Q.top();
			Q.pop();
			if (dist > D[i][now])	continue;
			for (auto [next, cost] : V[now]) {
				if (D[i][next] == -1 || D[i][next] > dist + cost) {
					D[i][next] = dist + cost;
					Q.emplace(D[i][next], next);
				}
			}
		}
	}

	for (; Q--;) {
		int s, e;
		cin >> s >> e;
		ll mn = 1e18;
		for (int i = 1; i <= B; i++) {
			if (D[i][s] == -1 || D[i][e] == -1)	continue;
			mn = min(mn, D[i][s] + D[i][e]);
		}
		cout << (mn == 1e18 ? -1 : mn) << '\n';
	}

	
}