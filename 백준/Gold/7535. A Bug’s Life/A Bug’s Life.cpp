#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		
		int n, m;
		cin >> n >> m;
		vector<vector<int>> V(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}

		vector<int> gen(n + 1);
		bool paradox = 0;
		for (int i = 1; i <= n; i++) {
			if (gen[i])	continue;
			gen[i] = 1;
			queue<pair<int, int>> Q;
			Q.push({ i,1 });
			while (!Q.empty()) {
				auto [now, gender] = Q.front();
				int opposite = gender == 1 ? 2 : 1;
				Q.pop();
				for (int next : V[now]) {
					if (!gen[next]) {
						Q.push({ next, opposite });
						gen[next] = opposite;
					}
					else if (gen[next] == opposite)	continue;
					else {
						paradox = 1;
						break;
					}
				}
			}
			if (paradox)	break;
		}
		cout << "Scenario #" << t << ":\n";
		if (!paradox)	cout << "No suspicious bugs found!\n\n";
		else	cout << "Suspicious bugs found!\n\n";
	}
}