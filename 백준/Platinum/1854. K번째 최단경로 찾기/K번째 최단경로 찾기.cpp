#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> V(n + 1);
	for (; m--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
	}

	vector<__gnu_pbds::priority_queue<int, less<int>, __gnu_pbds::pairing_heap_tag>> D(n + 1);
	D[1].push(0);
	__gnu_pbds::priority_queue<pair<int,int>, greater<pair<int,int>>, __gnu_pbds::pairing_heap_tag> Q;
	Q.push({0, 1});
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (D[now].size() == k && dist > D[now].top())	continue;
		for (auto& [next, cost] : V[now]) {
			int res = dist + cost;
			if (D[next].size() < k) {
				D[next].push(res);
				Q.push({res, next});
			}
			else if (D[next].size() == k && res < D[next].top()) {
				D[next].pop();
				D[next].push(res);
				Q.push({res, next});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (D[i].size() < k)	cout << "-1\n";
		else	cout << D[i].top() << '\n';
	}

}