#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
int graph1[1001][1001];
int visit1[1001] = { 0 };
int visit2[1001] = { 0 };
vector<vector<int> > graph2(1001);
queue<int> Q;

/*
void dfs1(int node) {
	visit[node] = 1;
	cout << node << ' ';
	for (int i = 1; i <= N; i++) {
		if (!visit[i])
			dfs1(i);
	}
}
*/

void dfs(int node) {
	if (visit1[node] == 0) {
		visit1[node] = 1;
		cout << node << ' ';
		for (int i = 0; i < graph2[node].size(); i++) {
			if (!visit1[graph2[node][i]])
				dfs(graph2[node][i]);
		}
	}
}

void bfs(int node) {
	Q.push(node);
	visit2[node] = 1;
	while (!Q.empty()) {
		int c = Q.front();
		Q.pop();
		cout << c << ' ';
		for (int i = 1; i <= N; i++) {
			if (graph1[c][i] == 1 && !visit2[i]) {
				visit2[i] = 1;
				Q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph1[a][b] = 1;
		graph1[b][a] = 1;

		graph2[a].push_back(b);
		graph2[b].push_back(a);
	}
	for (int i = 0; i < graph2.size(); i++)
		sort(graph2[i].begin(), graph2[i].end());
	dfs(V);
	cout << '\n';
	bfs(V);
}