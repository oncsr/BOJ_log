#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V(5001);
int dijk(int s, int e) {
	vector<int> D(5001, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
	D[s] = 0;
	Q.emplace(0, s);
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [next, cost] : V[now]) {
			if (D[next] == -1 || D[next] > dist + cost) {
				D[next] = dist + cost;
				Q.emplace(D[next], next);
			}
		}
	}
	return D[e];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int v, e, p;
	cin >> v >> e >> p;

	for (; e--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	cout << (dijk(1, v) == dijk(p, 1) + dijk(p, v) ? "SAVE HIM" : "GOOD BYE");

}