#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	pair<int, int> arr[200001]{};
	vector<vector<pair<int, int>>> X(100001), Y(100001);
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x,y };
		X[x].emplace_back(y, i);
		Y[y].emplace_back(x, i);
	}
	vector<vector<pair<int, ll>>> G(200001), S(200001);

	for (int i = 1; i <= N; i++) {
		sort(X[i].begin(), X[i].end());
		for (int j = 1; j < X[i].size(); j++) {
			auto [p, a] = X[i][j - 1];
			auto [q, b] = X[i][j];
			S[a].emplace_back(b, q - p);
			S[b].emplace_back(a, q - p);
		}
	}
	for (int i = 1; i <= M; i++) {
		sort(Y[i].begin(), Y[i].end());
		for (int j = 1; j < Y[i].size(); j++) {
			auto [p, a] = Y[i][j - 1];
			auto [q, b] = Y[i][j];
			G[a].emplace_back(b, q - p);
			G[b].emplace_back(a, q - p);
		}
	}
	// D[i][0] = 세로가 열려있을 때
	// D[i][1] = 가로가 열려있을 때

	vector<vector<ll>> D(200001, vector<ll>(2, -1));
	pair<ll, ll> ans = { -1,-1 };
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> Q;
	for (auto& [y, i] : X[1]) {
		D[i][0] = y - 1;
		Q.emplace(y - 1, i, 0);
	}

	while (!Q.empty()) {
		auto [d, n, v] = Q.top();
		Q.pop();
		if (d > D[n][v])	continue;
		auto [x, y] = arr[n];
		for (auto& [i, c] : G[n]) {
			ll r = d + c + (v ? 0 : 1);
			if (D[i][1] == -1 || D[i][1] > r) {
				D[i][1] = r;
				Q.emplace(r, i, 1);
			}
		}
		for (auto& [i, c] : S[n]) {
			ll r = d + c + (v ? 1 : 0);
			if (D[i][0] == -1 || D[i][0] > r) {
				D[i][0] = r;
				Q.emplace(r, i, 0);
			}
		}
		if (x == N) {
			ll r = d + M - y + (v ? 1 : 0);
			if (ans.first == -1 || ans.first > r)	ans.first = r;
		}
		if (y == M) {
			ll r = d + N - x + (v ? 0 : 1);
			if (ans.second == -1 || ans.second > r)	ans.second = r;
		}
	}
	
	auto [a, b] = ans;
	if (a == -1)	cout << b;
	else if (b == -1)	cout << a;
	else	cout << min(a, b);

}