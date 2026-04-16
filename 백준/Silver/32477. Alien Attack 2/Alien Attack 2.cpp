#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m;
	vector<vector<int>> V(200001);
	
	for (cin >> n >> m; m--;) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	bitset<200001> vis;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i])	continue;
		int cnt = 0;
		queue<int> Q;
		vis[i] = 1;
		Q.push(i);
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			cnt++;
			for (int j : V[x]) {
				if (!vis[j])	vis[j] = 1, Q.push(j);
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;

}