#include <iostream>
#include <queue>
using namespace std;

/*
* 2022.12.13
* [used algorithm]
* => bfs
* [point]
* => 벽을 부술 수 있는 상태의 방문 여부랑
* 부술 수 없는 상태의 방문 여부를 따로 관리
*/

struct node {
	int x, y, t, b;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k, map[1000][1000]{}, v[1000][1000][11]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	string a;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++)	map[i][j] = a[j] - '0';
	}
	node s = { 0,0,1,k };
	v[0][0][k]++;
	queue<node> Q;
	Q.push(s);
	bool suc = false;
	while (!Q.empty()) {
		node now = Q.front();
		Q.pop();
		if (now.x == n - 1 && now.y == m - 1) {
			suc = true;
			cout << now.t;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int x = now.x + dir[i][0];
			int y = now.y + dir[i][1];
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (!map[x][y]) {
					if (!v[x][y][now.b]) {
						Q.push({ x,y,now.t + 1,now.b });
						v[x][y][now.b]++;
					}
				}
				else if (now.b && !v[x][y][now.b - 1]) {
					Q.push({ x,y,now.t + 1,now.b - 1 });
					v[x][y][now.b - 1]++;
				}
			}
		}
	}
	if (!suc)	cout << -1;
}