#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V(100001);
int c = 0, vis[100001]{}, edge[220001]{};
void dfs(int n) {
	for (auto &[i, a] : V[n]) {
		if (!edge[a]) {
			edge[a] = ++c;
			cout << n << ' ' << i << ' ' << edge[a] << '\n';
		}
		if (vis[i])	continue;
		vis[i]++;
		dfs(i);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].emplace_back(b, i);
		V[b].emplace_back(a, i);
	}
	dfs(1);
    
}