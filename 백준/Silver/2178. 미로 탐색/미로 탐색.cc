#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;


int main() {
	int n, m;	cin >> n >> m;
	int mat[101][101];
	for (int i = 0; i < n; i++) {
		string a;	cin >> a;
		while (a.size() != m) {
			string a;	cin >> a;
		}
		for (int j = 0; j < m; j++) {
			if (a[j] == '0') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	queue<pair<int, int>> q;
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	int visited[101][101];
	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy < 0 || xx < 0 || yy >= n || xx >= m)	continue;
			if (visited[yy][xx] == 0 && mat[yy][xx] == 1) {
				q.push({ yy,xx });
				visited[yy][xx] = visited[y][x] + 1;
			}
		}
	}
	cout << visited[n - 1][m - 1] << '\n';
	return 0;
}