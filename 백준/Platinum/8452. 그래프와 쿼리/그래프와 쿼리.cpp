#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<pair<int, int>> edge(M);
	for (auto& [a, b] : edge)	cin >> a >> b;

	vector<int> rem(M);
	vector<pair<char, int>> query(Q);
	for (auto& [a, b] : query) {
		cin >> a >> b;
		if (a == 'U')	rem[b - 1]++;
	}

	vector<vector<int>> V(N + 1);
	for (int i = 0; i < M; i++) {
		if (rem[i])	continue;
		auto [a, b] = edge[i];
		V[a].push_back(b);
	}

	vector<int> D(N + 1, -1);
	queue<pair<int, int>> q;
	vector<int> v(N + 1);
	v[1]++;
	D[1] = 0;
	q.emplace(1, 0);
	while (!q.empty()) {
		auto [now, dist] = q.front();
		q.pop();
		for (int i : V[now]) {
			if (v[i])	continue;
			D[i] = dist + 1;
			v[i]++;
			q.emplace(i, D[i]);
		}
	}
	vector<int> ans;
	for (int i = Q - 1; i >= 0; i--) {
		auto [a, b] = query[i];
		if (a == 'U') {
			auto [x, y] = edge[b - 1];
			V[x].push_back(y);
			if (D[x] == -1)	continue;
			if (D[y] == -1 || D[y] > D[x] + 1) {
				D[y] = D[x] + 1;
				q.emplace(y, D[y]);
				while (!q.empty()) {
					auto [now, dist] = q.front();
					q.pop();
					for (int j : V[now]) {
						if (D[j] == -1 || D[j] > dist + 1) {
							D[j] = dist + 1;
							q.emplace(j, D[j]);
						}
					}
				}
			}
			
		}
		else	ans.push_back(D[b]);
	}
	for (int i = ans.size() - 1; i >= 0; i--)	cout << ans[i] << '\n';
}