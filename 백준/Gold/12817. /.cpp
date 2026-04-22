#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll sz[1000001]{}, ans[1000001]{};
vector<vector<int>> V(1000001);

void dfs(int n, int p) {
	sz[n] = 1, ans[n] = N - 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
		ans[n] += sz[i] * (N - sz[i]);
	}
	ans[n] += sz[n] * (N - sz[n]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= N; i++)	cout << ans[i] << '\n';
}