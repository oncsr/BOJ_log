#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<vector<tuple<int, int, int>>> V(N + 1);
		for (; K--;) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			V[a].emplace_back(b, c, d);
		}

		vector<vector<int>> D(N + 1, vector<int>(M + 1, -1));
		D[1][0] = 0;
		queue<tuple<int, int, int>> Q;
		Q.emplace(0, 0, 1);
		while (!Q.empty()) {
			auto [dist, money, now] = Q.front();
			Q.pop();
			if (dist > D[now][money])	continue;
			for (auto& [next, fee, cost] : V[now]) {
				if (money + fee > M)	continue;
				if (D[next][money + fee] == -1 || D[next][money + fee] > dist + cost) {
					D[next][money + fee] = dist + cost;
					Q.emplace(dist + cost, money + fee, next);
				}
			}
		}
		int ans = 1e9;
		for (int i = 1; i <= M; i++) {
			if (D[N][i] == -1)	continue;
			ans = min(ans, D[N][i]);
		}
		if (ans == 1e9)	cout << "Poor KCM\n";
		else	cout << ans << '\n';

	}

}