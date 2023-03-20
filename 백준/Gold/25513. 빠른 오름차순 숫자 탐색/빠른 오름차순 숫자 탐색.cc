#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int map[5][5]{};

int bfs(ii pos, ii dest) {
	int visit[5][5]{};
	queue<pair<ii, int> > Q;
	visit[pos.first][pos.second]++;
	Q.push({ pos,0 });
	while (!Q.empty()) {
		ii now = Q.front().first;
		int dist = Q.front().second;
		Q.pop();
		if (now == dest)	return dist;
		for (int i = 0; i < 4; i++) {
			int x = now.first + dir[i][0];
			int y = now.second + dir[i][1];
			if (x >= 0 && x < 5 && y >= 0 && y < 5 && !visit[x][y] && map[x][y] != -1) {
				visit[x][y]++;
				Q.push({ {x,y},dist + 1 });
			}
		}
	}
	return -1;
}


int main() {
	ii arr[7]{};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0)	arr[map[i][j]] = { i,j };
		}
	int r, c;
	cin >> r >> c;
	int s = 0;
	ii pos = { r,c };
	for (int i = 1; i <= 6; i++) {
		int g = bfs(pos, arr[i]);
		if (g == -1) {
			cout << -1;
			return 0;
		}
		pos = arr[i];
		s += g;
	}
	cout << s;
}