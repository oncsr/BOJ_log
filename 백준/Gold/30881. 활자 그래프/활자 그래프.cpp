#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T, over = 1000000000000000000LL + 3;
vector<vector<vector<pair<ll, ll>>>> graph;
vector<ll> sz;
vector<pair<ll, ll>> val;

ll dijk(int num, int s, int e) {
	auto& V = graph[num];
	vector<ll> D(sz[num], -1);
	D[s] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	Q.emplace(0, s);
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto& [next, cost] : V[now]) {
			if (cost > 1000000000000000000LL)	continue;
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
	cin >> T;
	graph.resize(T + 1);
	sz.resize(T + 1);
	val.resize(T + 1);
	for (int i = 1; i <= T; i++) {
		int N, M;
		cin >> N >> M;
		sz[i] = N + 1;
		graph[i].resize(N + 1);
		for (; M--;) {
			ll a, b, c;
			cin >> a >> b >> c;
			if (c < 0) {
                if(0 <= val[-c].first && val[-c].first <= 1000000000000000000LL)    graph[i][a].emplace_back(b, val[-c].first);
				if(0 <= val[-c].second && val[-c].second <= 1000000000000000000LL)    graph[i][b].emplace_back(a, val[-c].second);
			}
			else	graph[i][a].emplace_back(b, c);
		}
		if (i == T) {
			ll ans = dijk(T, 1, 2);
			cout << (ans > 1000000000000000000LL ? -1 : ans);
			return 0;
		}
        val[i].first = dijk(i, 1, 2);
        val[i].second = dijk(i, 2, 1);
        if(val[i].first == -1 || val[i].first > 1000000000000000000LL)    val[i].first = over;
        if(val[i].second == -1 || val[i].second > 1000000000000000000LL)    val[i].second = over;

	}


}