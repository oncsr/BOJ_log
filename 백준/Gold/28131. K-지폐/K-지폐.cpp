#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K, S, T;
	cin >> N >> M >> K >> S >> T;

	vector<vector<pair<int, int>>> V(N + 1);
	vector<vector<int>> D(N + 1, vector<int>(K, -1));

	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
	}

	D[S][0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
	Q.emplace(0, S);
	while (!Q.empty()) {
		auto [d, n] = Q.top();
		Q.pop();
		if (d > D[n][d % K])	continue;
		for (auto [i, c] : V[n]) {
			int res = d + c, k = res % K;
			if (D[i][k] == -1 || D[i][k] > res) {
				D[i][k] = res;
				Q.emplace(res, i);
			}
		}
	}

	if (D[T][0] == -1)	cout << "IMPOSSIBLE";
	else	cout << D[T][0];

}