#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<vector<tuple<int, int, int>>> V(100);

	for (; M--;) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		V[a].emplace_back(c, d, b);
		V[b].emplace_back(e, d, a);
	}

	for (int i = 0; i < N; i++) {
		if (V[i].empty())	continue;
		sort(V[i].begin(), V[i].end());
		int g = get<0>(V[i][0]);
		for (int j = V[i].size() - 1; j >= 0; j--) {
			if (get<0>(V[i][j]) == g)	break;
			V[i].pop_back();
		}
	}

	vector<pair<int, int>> D(100, make_pair(1e9, 0));
	D[S] = make_pair(0, 0);
	for (int _ = 1; _ <= N; _++) {
		vector<int> ch;
		for (int i = 0; i < N; i++) {
			if (D[i].first == 1e9)	continue;
			for (auto& [a, b, c] : V[i]) {
				int nxt = c, trd = a, len = b;
				if (D[nxt].first > D[i].first + trd) {
					D[nxt].first = D[i].first + trd;
					D[nxt].second = D[i].second + len;
					ch.push_back(nxt);
				}
				else if (D[nxt].first == D[i].first + trd && D[nxt].second > D[i].second + len) {
					D[nxt].second = D[i].second + len;
				}
			}
		}
		if (_ == N && ch.size()) {
			bool c1 = 0;
			queue<int> Q;
			int vis[100]{};
			for (int i : ch)	vis[i] = 2;
			Q.push(S);
			while (!Q.empty()) {
				int n = Q.front();
				Q.pop();
				for (auto& [a, b, c] : V[n]) {
					if (vis[c] == 1)	continue;
					if (vis[c] == 2) { c1 = 1; break; }
					vis[c]++;
					Q.push(c);
				}
			}
			Q = queue<int>();
			fill(vis, vis + 100, 0);
			for (int i : ch)	vis[i]++, Q.push(i);
			while (!Q.empty()) {
				int n = Q.front();
				Q.pop();
				for (auto& [a, b, c] : V[n]) {
					if (vis[c])	continue;
					vis[c]++;
					Q.push(c);
				}
			}
			if (vis[T] && c1)	return cout << "UNBOUND", 0;
		}
	}
	auto [a, b] = D[T];
	if (a == 1e9)	cout << "VOID";
	else	cout << a << ' ' << b;

}