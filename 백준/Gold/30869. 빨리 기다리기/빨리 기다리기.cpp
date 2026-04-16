#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	
	vector<vector<tuple<int, int, int>>> V(N + 1);
	for (int s, e, t, g; M--;) {
		cin >> s >> e >> t >> g;
		V[s].emplace_back(e, t, g);
	}

	int D[501][501]{};	memset(D, -1, sizeof(D));
	D[1][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	Q.emplace(0, 1, 0);
	while (!Q.empty()) {
		auto [d, n, k] = Q.top();	Q.pop();
		if (d > D[n][k])	continue;
		for (auto& [i, t, g] : V[n]) {
			if (d % g && k < K) {
				int res = d + t;
				if (D[i][k + 1] == -1 || D[i][k + 1] > res) {
					D[i][k + 1] = res;
					Q.emplace(res, i, k + 1);
				}
			}
			int res = d / g * g + t;
			if (d % g)	res += g;
			if (D[i][k] == -1 || D[i][k] > res) {
				D[i][k] = res;
				Q.emplace(res, i, k);
			}
		}
	}
	int mn = 2e9;
	for (int i = 0; i <= K; i++)	if (D[N][i] != -1)	mn = min(mn, D[N][i]);
	cout << (mn == 2e9 ? -1 : mn);

}