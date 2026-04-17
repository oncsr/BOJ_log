#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, L;
vector<vector<pair<int, int>>> V(100000);
vector<int> vis(100000);
int down[100000]{}, down2[100000]{}, up[100000]{};
int val = 2e9;

int dfs1(int n, int p) {
	vis[n]++;
	int mx1 = 0, mx2 = 0;
	for (auto& [i, c] : V[n]) {
		if (i == p)	continue;
		int g = dfs1(i, n) + c;
		if (g > mx1)	mx2 = mx1, mx1 = g;
		else if (g > mx2)	mx2 = g;
	}
	down2[n] = mx2;
	return down[n] = mx1;
}

void dfs2(int n, int p) {
	val = min(val, max(down[n], up[n]));
	for (auto& [i, c] : V[n]) {
		if (i == p)	continue;
		if (down[n] == down[i] + c)	up[i] = max(up[n], down2[n]) + c;
		else	up[i] = max(up[n], down[n]) + c;
		dfs2(i, n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M >> L;
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		V[a].emplace_back(b, t);
		V[b].emplace_back(a, t);
	}

	vector<int> res;
	for (int i = 0; i < N; i++) {
		if (vis[i])	continue;
		val = 2e9;
		dfs1(i, -1);
		dfs2(i, -1);
		res.push_back(val);
	}
	sort(res.begin(), res.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < N; i++)	ans = max(ans, down[i] + down2[i]);
	
	if (res.size() == 1) { cout << ans; return 0; }
	ans = max(ans, res[0] + res[1] + L);
	if (res.size() > 2)	ans = max(ans, res[1] + res[2] + 2 * L);
	cout << ans;

}