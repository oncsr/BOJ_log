#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<tuple<int, ll, int, bool>>> V(N + 1);
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c, i, 1);
		V[b].emplace_back(a, c * 2, i, 0);
	}

	vector<ll> D(N + 1, -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	D[1] = 0;
	Q.emplace(0, 1);
	vector<int> ans(M, 1);
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [a, b, c, d] : V[now]) {
			if (D[a] == -1 || D[a] > dist + b) {
				D[a] = dist + b;
				Q.emplace(D[a], a);
				if (!d)	ans[c] = d;
			}
		}
	}
	ll S = 0;
	for (int i = 2; i <= N; i++)	S += D[i];
	cout << S << '\n';
	for (int i = 0; i < M; i++)	cout << ans[i] << ' ';

}