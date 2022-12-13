#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, map[1000][1000]{}, v[1000][1000]{}, is[1000][1000]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int mat[500001]{};
	vector<pair<int, int> > wall;
	string a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j] && !v[i][j]) {
				queue<pair<int, int> > Q;
				int s = 1;
				v[i][j]++;
				is[i][j] = ++cnt;
				Q.push({ i,j });
				while (!Q.empty()) {
					pair<int, int> now = Q.front();
					is[now.first][now.second] = cnt;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int x = now.first + dir[k][0];
						int y = now.second + dir[k][1];
						if (x >= 0 && x < n && y >= 0 && y < m && !v[x][y] && !map[x][y]) {
							Q.push({ x,y });
							v[x][y]++;
							s++;
						}
					}
				}
				mat[cnt] = s;
			}
			else	wall.push_back({ i,j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				int s = 1, visit[4]{}, id = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if (x >= 0 && x < n && y >= 0 && y < m && !map[x][y]) {
						bool yes = true;
						for (int g = 0; g < id; g++) {
							if (visit[g] == is[x][y]) {
								yes = false;
								break;
							}
						}
						if (yes)	s += mat[is[x][y]], visit[id++] = is[x][y];
					}
				}
				cout << s % 10;
			}
			else	cout << 0;
		}
		cout << '\n';
	}
}