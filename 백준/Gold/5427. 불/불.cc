#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define x first
#define y second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		queue<iii> fire;
		queue<iii> sang;
		// J = -2, . = -1, # = -2, F = 0
		int R, C, map[1000][1000]{};
		int dir[4][2] = { {1,0},{0,1},{-1,0}, {0,-1} };
		cin >> C >> R;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char t;
				cin >> t;
				if (t == '#')	map[i][j] = -2;
				if (t == '.')	map[i][j] = -1;
				if (t == '@') {
					map[i][j] = -1;
					sang.push({ {i,j}, 0 });
				}
				if (t == '*')	fire.push({ {i,j},0 });
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
		while (!sang.empty()) {
			ii now = sang.front().x;
			int time = sang.front().y;
			sang.pop();
			if (now.x == 0 || now.x == R - 1 || now.y == 0 || now.y == C - 1) {
				cout << time + 1 << '\n';
				find++;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx = now.x + dir[i][0];
				int yy = now.y + dir[i][1];
				if (xx >= 0 && xx < R && yy >= 0 && yy < C && !visit2[xx][yy]) {
					if (map[xx][yy] == -1 || (map[xx][yy] >= 0 && time + 1 < map[xx][yy])) {
						visit2[xx][yy]++;
						sang.push({ {xx,yy}, time + 1 });
					}
				}
			}
		}
		if (!find)	cout << "IMPOSSIBLE\n";
	}
}