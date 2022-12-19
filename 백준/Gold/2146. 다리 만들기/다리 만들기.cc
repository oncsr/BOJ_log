#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, r;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, map[100][100]{}, mn = 10001;
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	cin >> map[i][j];

	int vis[100][100]{}, id = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || !map[i][j])	continue;
			queue<pair<int, int> > Q;
			Q.push({ i,j });
			map[i][j] = ++id;
			while (!Q.empty()) {
				pair<int, int> now = Q.front();
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int x = now.first + dir[k][0];
					int y = now.second + dir[k][1];
					if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && map[x][y]) {
						map[x][y] = id;
						vis[x][y]++;
						Q.push({ x,y });
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j])	continue;
			bool find = false;
			queue<node> Q;
			int visit[100][100]{};
			for (int k = 0; k < 4; k++) {
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if (x >= 0 && x < n && y >= 0 && y < n && !map[x][y]) {
					find = true;
					Q.push({ x,y,1 });
					visit[x][y]++;
				}
			}
			bool br = false;
			int num = map[i][j];
			while (!Q.empty()) {
				node now = Q.front();
				Q.pop();
				if (br)	break;
				for (int k = 0; k < 4; k++) {
					int x = now.x + dir[k][0];
					int y = now.y + dir[k][1];
					if (x >= 0 && x < n && y >= 0 && y < n && !visit[x][y]) {
						if (!map[x][y]) {
							visit[x][y]++;
							Q.push({ x,y,now.r + 1 });
						}
						else {
							if (map[x][y] != num) {
								mn = min(mn, now.r);
								br = true;
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << mn;
}