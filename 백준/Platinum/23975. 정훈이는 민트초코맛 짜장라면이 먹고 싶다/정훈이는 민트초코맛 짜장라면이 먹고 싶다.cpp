#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> root(N + 1);
	iota(root.begin(), root.end(), 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	vector<vector<pair<int, int>>> V(N + 1);
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	vector<int> D(N + 1, -1);
	vector<int> prev(N + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
	D[1] = 0;
	Q.emplace(0, 1);
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [next, cost] : V[now]) {
			if (D[next] == -1 || D[next] > dist + cost) {
				D[next] = dist + cost;
				prev[next] = now;
				Q.emplace(D[next], next);
			}
			else if (D[next] == dist + cost && now > prev[next])	prev[next] = now;
		}
	}

	for (; K--;) {
		int a;
		cin >> a;
		if (D[a] == -1) { cout << "-1\n"; continue; }
		int x = find(a);
		while (!arr[x] && x != 1) {
			int y = find(prev[x]);
			root[x] = y;
			x = y;
		}
		if (!arr[x])	cout << "-1\n";
		else {
			cout << x << '\n';
			arr[x]--;
		}
	}

}
