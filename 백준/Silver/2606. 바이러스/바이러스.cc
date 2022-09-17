#include <iostream>
#include <queue>
using namespace std;
int com[101][101];
int visit[101] = { 0 };
int n;
int v;
queue<int> Q;

int bfs(int start) {
	int cnt = 0;
	Q.push(start);
	visit[start] = 1;
	while (!Q.empty()) {
		int c = Q.front();
		Q.pop();
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && com[c][i] == 1) {
				Q.push(i);
				visit[i] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	cin >> v;
	for (int i = 0; i < v; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}
	cout << bfs(1) - 1 << '\n';
}