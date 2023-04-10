#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001]{};
int N, M, V;
int visit1[1001]{}, visit2[1001]{};

void DFS(int n) {
	cout << n << ' ';
	for (int i = 1; i <= N; i++) {
		if (visit1[i] == 0 && graph[n][i]) {
			visit1[i]++;
			DFS(i);
		}
	}
}

void BFS(int n) {
	queue<int> Q;
	visit2[n]++;
	Q.push(n);
	while (!Q.empty()) {
		int now = Q.front();
		cout << now << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (visit2[i] == 0 && graph[now][i]) {
				visit2[i]++;
				Q.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// a에서 b로, b에서 a로 가는 간선이 존재한다고 표시
		graph[a][b] = graph[b][a] = 1;
	}

	visit1[V]++;
	DFS(V);
	cout << '\n';
	BFS(V);

}