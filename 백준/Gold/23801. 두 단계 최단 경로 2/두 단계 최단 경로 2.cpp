#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, ll>;

vector<vector<ii>> V;
int N, M;

int dijk(int s, int e) {
	vector<int> D(N + 1, -1);
	D[s] = 0;
	priority_queue<ii, vector<ii>, greater<>> Q;
	Q.push({ 0,s });
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [next, cost] : V[now]) {
			if (D[next] == -1 || D[next] > D[now] + cost) {
				D[next] = D[now] + cost;
				Q.push({ D[next], next });
			}
		}
	}
	return D[e];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	V.resize(N + 1);
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	int x, z;
	cin >> x >> z;

	vector<vector<ll>> D(N + 1, vector<ll>(2, -1));
	vector<int> E = { x,z };
	for (int i = 0; i < 2; i++) {
		D[E[i]][i] = 0;
		priority_queue<ii, vector<ii>, greater<>> Q;
		Q.push({ 0,E[i] });
		while (!Q.empty()) {
			auto [dist, now] = Q.top();
			Q.pop();
			if (dist > D[now][i])	continue;
			for (auto [next, cost] : V[now]) {
				if (D[next][i] == -1 || D[next][i] > D[now][i] + cost) {
					D[next][i] = D[now][i] + cost;
					Q.push({ D[next][i], next});
				}
			}
		}
	}
	ll ans = 1e15;
	int p;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		if (D[a][0] == -1 || D[a][1] == -1)	continue;
		ans = min(ans, D[a][0] + D[a][1]);
	}
	cout << (ans == 1e15 ? -1 : ans);


}