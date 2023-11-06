#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<ii>> V(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ c,b });
		V[b].push_back({ c,a });
	}

	int X, Y;
	cin >> X >> Y;
	priority_queue<ii> Q;
	vector<int> D(N + 1, 1e9 + 1);
	Q.push({ 1e9 + 1, X });
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist < D[now])	continue;
		if (now == Y) {
			cout << D[now];
			return 0;
		}
		for (auto [cost, next] : V[now]) {
			if (D[next] == 1e9 + 1 || D[next] < min(D[now], cost)) {
				D[next] = min(D[now], cost);
				Q.push({ D[next], next });
			}
		}
	}

}