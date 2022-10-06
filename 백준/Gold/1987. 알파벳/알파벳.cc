#include <iostream>
using namespace std;

char map[20][20]{};
int visit[26]{};
int r, c, mx = 1, cnt = 1;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx >= 0 && xx < r && yy >= 0 && yy < c && !visit[map[xx][yy] - 'A']) {
			visit[map[xx][yy] - 'A'] = 1;
			cnt++;
			mx = max(mx, cnt);
			dfs(xx, yy);
			cnt--;
			visit[map[xx][yy] - 'A'] = 0;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
	visit[map[0][0] - 'A'] = 1;
	dfs(0, 0);
	cout << mx;
}