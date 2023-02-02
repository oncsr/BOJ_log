#include <bits/stdc++.h>
using namespace std;
using iii = pair<pair<int, int>, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int R, C;
	char map[50][50]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	// S = -2, D = -3, X = -4, . = -1
	// 물이 차오르는 시간은 real_map[i][j]로 정함(0 이상)
	int real_map[50][50]{};
	cin >> R >> C;
	queue<iii> water;
	queue<iii> sss;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				real_map[i][j] = -3;
			}
			if (map[i][j] == 'S') {
				sss.push({ {i,j}, 0 });
				real_map[i][j] = -2;
			}
			if (map[i][j] == 'X') {
				real_map[i][j] = -4;
			}
			if (map[i][j] == '.') {
				real_map[i][j] = -1;
			}
			if (map[i][j] == '*') {
				water.push({ {i,j}, 0 });
			}
		}
	}
	int visit1[50][50]{};
	while (!water.empty()) {
		iii now = water.front();
		water.pop();
		for (int i = 0; i < 4; i++) {
			int x = now.first.first + dir[i][0];
			int y = now.first.second + dir[i][1];
			if (x >= 0 && x < R && y >= 0 && y < C && !visit1[x][y]) {
				if (real_map[x][y] == -2 || real_map[x][y] == -1) {
					visit1[x][y]++;
					water.push({ {x, y}, now.second + 1 });
					real_map[x][y] = now.second + 1;
				}
			}
		}
	}
	int visit2[50][50]{}, find = 0;
	while (!sss.empty()) {
		iii now = sss.front();
		sss.pop();
		if (real_map[now.first.first][now.first.second] == -3) {
			cout << now.second;
			find++;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int x = now.first.first + dir[i][0];
			int y = now.first.second + dir[i][1];
			if (x >= 0 && x < R && y >= 0 && y < C && !visit2[x][y]) {
				if (real_map[x][y] == -3 || real_map[x][y] == -1 || (real_map[x][y] >= 0 && now.second + 1 < real_map[x][y])) {
					visit2[x][y]++;
					sss.push({ {x,y},now.second + 1 });
				}
			}
		}
	}
	if (!find)	cout << "KAKTUS";
}