#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	vector<vector<tuple<int, int, int>>> V(100001);
	for (cin >> N >> M; M--;) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		V[a].emplace_back(b, c, d);
		V[b].emplace_back(a, c, d);
	}

	auto dijk = [&](int t) -> int {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
		vector<int> D(N + 1, -1);
		Q.emplace(t, 1);
		D[1] = t;
		while (!Q.empty()) {
			auto [d, n] = Q.top();
			Q.pop();
			if (d > D[n])	continue;
			for (auto& [i, c, t] : V[n]) {
				if (d + c > t)	continue;
				if (D[i] == -1 || D[i] > d + c) {
					D[i] = d + c;
					Q.emplace(D[i], i);
				}
			}
		}
		return D[N];
	};

	if (dijk(0) == -1)	return cout << -1, 0;

	int s = 0, e = 1e9, m = (s + e + 1) >> 1;
	while (s < e) {
		if (dijk(m) == -1)	e = m - 1;
		else	s = m;
		m = (s + e + 1) >> 1;
	}
	cout << m;

}