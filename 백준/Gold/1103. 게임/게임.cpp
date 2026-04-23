#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int visit[2500]{}, mx = 0;
string a;
int map[51][51]{}, d[51][51]{}, n, m;

void dfs(int x, int y, int c) {
	d[x][y] = max(d[x][y], c);
	c = d[x][y];
	mx = max(mx, c);
	if (mx > n * m)	return;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0] * map[x][y];
		int yy = y + dir[i][1] * map[x][y];
		if (xx > 0 && xx <= n && yy > 0 && yy <= m && map[xx][yy]) {
			if (c + 1 > d[xx][yy])
				dfs(xx, yy, c + 1);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 1; j <= m; j++) {
			if (a[j - 1] == 'H')	map[i][j] = 0;
			else	map[i][j] = a[j - 1] - '0';
		}
	}
	dfs(1, 1, 1);
	cout << (mx > n * m ? -1 : mx);
}