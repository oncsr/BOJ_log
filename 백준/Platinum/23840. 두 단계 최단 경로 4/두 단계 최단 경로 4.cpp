#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll weight[21][21]{};
ll dist[21][1 << 21]{};
int P;

ll dp(int n, int k) {
	if (dist[n][k])	return dist[n][k];
	int g = k - (1 << n);
	int d = 0;
	while ((1 << d) <= g) {
		if (g & (1 << d)) {
			if (!dist[d][g])	dist[d][g] = dp(d, g);
			if (!dist[n][k])	dist[n][k] = dist[d][g] + weight[d][n];
			else	dist[n][k] = min(dist[n][k], dist[d][g] + weight[d][n]);
		}
		d++;
	}
	return dist[n][k];

}

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, ll>>> V(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	int X, Y;
	cin >> X >> Y >> P;
	vector<vector<ll>> D(N + 1, vector<ll>(P + 1, -1));
	vector<ll> L;
	L.push_back(X);
	for (int i = 0; i < P; i++) {
		int a;
		cin >> a;
		L.push_back(a);
	}

	for (int i = 0; i < L.size(); i++) {
		int start = L[i];

		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
		Q.push({ 0,start });
		D[start][i] = 0;
		while (!Q.empty()) {
			auto [dist, now] = Q.top();
			Q.pop();
			if (dist > D[now][i])	continue;
			for (auto [next, cost] : V[now]) {
				if (D[next][i] == -1 || (D[next][i] > D[now][i] + cost)) {
					D[next][i] = D[now][i] + cost;
					Q.push({ D[next][i], next });
				}
			}
		}

	}
	L.push_back(Y);
	for (int i = 1; i < P + 1; i++) {
		ll cost;
		if (D[L[i]][0] == -1)	cost = 1e15;
		else	cost = D[L[i]][0];
		dist[i - 1][1 << (i - 1)] = cost;
	}

	for (int i = 1; i < L.size(); i++) {
		for (int j = i + 1; j < L.size(); j++) {
			// L[i] -> i-1
			ll cost;
			if (D[L[j]][i] == -1)	cost = 1e15;
			else	cost = D[L[j]][i];
			weight[i - 1][j - 1] = weight[j - 1][i - 1] = cost;
		}
	}
	ll ans = dp(P, (1 << (P + 1)) - 1);
	cout << (ans >= 1e15 ? -1 : ans);

}