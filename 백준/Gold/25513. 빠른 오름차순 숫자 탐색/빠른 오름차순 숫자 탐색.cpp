#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

int map[5][5]{};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cx, cy;

int bfs(int x, int y, int tar) {
	queue<iii> Q;
	int vis[5][5]{};
	Q.push({ {x,y},0 });
	vis[x][y]++;
	while (!Q.empty()) {
		ii now = Q.front().first;
		int dis = Q.front().second;
		Q.pop();
		if (map[now.first][now.second] == tar) {
			cx = now.first, cy = now.second;
			return dis;
		}
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];
			if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && !vis[xx][yy] && map[xx][yy] != -1) {
				Q.push({ {xx,yy},dis + 1 });
				vis[xx][yy]++;
			}
		}
	}
	return -1;
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	int r, c, s = 0;
	cin >> r >> c;
	cx = r, cy = c;
	for (int i = 1; i <= 6; i++) {
		int g = bfs(cx, cy, i);
		if (g == -1) {
			cout << g;
			return 0;
		}
		s += g;
	}
	cout << s;
}