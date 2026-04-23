#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	char map[501][501]{};
	int visit[501][501]{};
	cin >> n >> m;
	int dir[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j];
			if (a[j] == 'H') {
				if (p1 == -1)	p1 = i, p2 = j;
				else	p3 = i, p4 = j;
			}
		}
	}
	visit[p1][p2]++;
	queue<pair<int, int> > Q;
	Q.push({ p1, p2 });
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++) {
			int x = now.first + dir[i][0];
			int y = now.second + dir[i][1];
			if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && map[x][y] != '#') {
				visit[x][y]++;
				Q.push({ x,y });
			}
		}
	}
	bool yes = false;
	Q.push({ p3,p4 });
	visit[p3][p4] += 2;
	if (visit[p3][p4] == 3)	yes = true;
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		if (yes)	break;
		for (int i = 0; i < 8; i++) {
			int x = now.first + dir[i][0];
			int y = now.second + dir[i][1];
			if (x >= 0 && x < n && y >= 0 && y < m && visit[x][y] < 2 && map[x][y] != '#') {
				visit[x][y] += 2;
				if (visit[x][y] == 3)	yes = true;
				Q.push({ x,y });
			}
		}
	}
	cout << (yes ? "JA" : "NEJ");
}