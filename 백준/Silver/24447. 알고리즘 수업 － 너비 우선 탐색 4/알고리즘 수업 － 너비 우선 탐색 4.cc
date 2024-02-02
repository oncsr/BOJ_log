#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, R;
	cin >> N >> M >> R;
	vector<ll> D(N + 1, -1);
	vector<ll> T(N + 1);
	vector<vector<int>> V(100001);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)	sort(V[i].begin(), V[i].end());

	int c = 0;
	queue<pair<int, int>> Q;
	Q.emplace(R, 0);
	D[R] = 0;
	T[R] = ++c;
	while (!Q.empty()) {
		auto [n, d] = Q.front();
		Q.pop();
		for (int i : V[n]) {
			if (T[i])	continue;
			T[i] = ++c;
			D[i] = d + 1;
			Q.emplace(i, d + 1);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= N; i++)	ans += D[i] * T[i];
	cout << ans;


}