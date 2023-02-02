#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define x first
#define y second

int main() {
	queue<iii> fire;
	queue<iii> jihun;
	// J = -2, . = -1, # = -2, F = 0
	int R, C, map[1000][1000]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0}, {0,-1} };
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char t;
			cin >> t;
			if (t == '#')	map[i][j] = -2;
			if (t == '.')	map[i][j] = -1;
			if (t == 'J') {
				map[i][j] = -1;
				jihun.push({ {i,j}, 0 });
			}
			if (t == 'F')	fire.push({ {i,j},0 });
		}
	}
	int visit1[1000][1000]{}, visit2[1000][1000]{};
	while (!fire.empty()) {
		ii now = fire.front().x;
		int time = fire.front().y;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if (xx >= 0 && xx < R && yy >= 0 && yy < C && !visit1[xx][yy]) {
				if (map[xx][yy] == -1) {
					visit1[xx][yy]++;
					fire.push({ {xx,yy},time + 1 });
					map[xx][yy] = time + 1;
				}
			}
		}
	}
	int find = 0;
	while (!jihun.empty()) {
		ii now = jihun.front().x;
		int time = jihun.front().y;
		jihun.pop();
		if (now.x == 0 || now.x == R - 1 || now.y == 0 || now.y == C - 1) {
			cout << time + 1;
			find++;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if (xx >= 0 && xx < R && yy >= 0 && yy < C && !visit2[xx][yy]) {
				if (map[xx][yy] == -1 || (map[xx][yy] >= 0 && time + 1 < map[xx][yy])) {
					visit2[xx][yy]++;
					jihun.push({ {xx,yy}, time + 1 });
				}
			}
		}
	}
	if (!find)	cout << "IMPOSSIBLE";
}