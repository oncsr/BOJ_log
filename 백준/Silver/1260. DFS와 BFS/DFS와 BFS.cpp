#include <bits/stdc++.h>
using namespace std;

int V[1001][1001]{};
int vis[1001]{}, N;

void dfs(int n) {
	cout << n << ' ';
	for (int i = 1; i <= N; i++) {
		if (!vis[i] && V[n][i]) {
			vis[i]++;
			dfs(i);
		}
	}
}

void bfs(int n) {
	queue<int> Q;
	Q.push(n);
	while (!Q.empty()) {
		int now = Q.front();
		cout << now << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (!vis[i] && V[now][i]) {
				vis[i]++;
				Q.push(i);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int M, S;
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a][b] = 1;
		V[b][a] = 1;
	}
	vis[S]++;
	dfs(S);
	fill(vis, vis + 1001, 0);
	vis[S]++;
	cout << '\n';
	bfs(S);

}