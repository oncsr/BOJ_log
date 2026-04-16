#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> V(N + 1);
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	vector<priority_queue<ll>> D(100001);
	D[1].push(0);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	Q.emplace(0, 1);
	while (!Q.empty()) {
		auto [d, n] = Q.top();
		Q.pop();
		if (d > D[n].top())	continue;
		for (auto [i, c] : V[n]) {
			ll res = d + c;
			if (D[i].empty() || D[i].size() < 2 || res < D[i].top()) {
				D[i].push(res);
				Q.emplace(res, i);
			}
			if (D[i].size() > 2)	D[i].pop();
		}
	}
	cout << D[N].top();

}