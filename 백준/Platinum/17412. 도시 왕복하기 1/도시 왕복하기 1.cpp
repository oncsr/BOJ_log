#include <bits/stdc++.h>
using namespace std;
#define SZ 401

int N, M;
int capacity[SZ][SZ]{}, flow[SZ][SZ]{};
vector<vector<int>> V(SZ);
vector<int> level(SZ);
vector<int> work(SZ);

bool bfs() {
	level = vector<int>(N + 1, -1);

	queue<int> Q;
	Q.push(1);
	level[1] = 0;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int next : V[now]) {
			if (level[next] != -1)	continue;
			if (capacity[now][next] - flow[now][next] <= 0)	continue;
			Q.push(next);
			level[next] = level[now] + 1;
		}
	}
	return level[2] != -1;
}

int dfs(int s, int v) {
	if (s == 2)	return v;
	for (int& i = work[s]; i < V[s].size(); i++) {
		int next = V[s][i];
		int C = capacity[s][next], F = flow[s][next];
		if (level[next] != level[s] + 1 || C - F <= 0)	continue;
		int R = dfs(next, min(v, C - F));
		if (R > 0) {
			flow[s][next] += R;
			flow[next][s] -= R;
			return R;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		capacity[a][b]++;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int ans = 0;

	while (bfs()) {
		work = vector<int>(N + 1);
		while (1) {
			int F = dfs(1, 1e9);
			if (!F)	break;
			ans += F;
		}
	}

	cout << ans;


}