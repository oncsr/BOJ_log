#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<vector<int>> V(200001);
	int deg_cp[200001]{}, deg[200001]{}, score[200001]{}, goal = N, same[200001]{};
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			same[a]++;
			goal--;
			continue;
		}
		V[a].push_back(b);
		deg[b]++;
		deg_cp[b]++;
		score[a]++;
	}

	int ans = 0, last = 2;
	for (int i = 1; i <= N; i++) {
		if (!deg[i] && !same[i] && last == 2) {
			queue<int> Q;
			Q.push(i);
			while (!Q.empty()) {
				int n = Q.front();
				last = deg_cp[n];
				same[n]++;
				ans += max(score[n], 1);
				Q.pop();
				for (int j : V[n]) {
					if (!--deg[j])	Q.push(j);
				}
			}
		}
	}

	int par[200001]{};
	function<void(int, int, int)> dfs = [&](int n, int p, int s) -> void {
		par[n] = p;
		for (int i : V[n]) {
			if (same[i] == 1)	continue;
			if (same[i] == s) {
				int cnt = 1, t = n;
				while (t) {
					cnt++;
					t = par[t];
				}
				ans += cnt;
				return;
			}
			if (i == p)	continue;
			same[i] = s;
			dfs(i, n, s);
		}
	};
	int s = 2;
	for (int i = 1; i <= N; i++) {
		if (same[i])	continue;
		if (!deg[i])	return cout << -1, 0;
		same[i] = s;
		dfs(i, 0, s++);
	}

	cout << ans;

}