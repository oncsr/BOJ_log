#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	int M, N, map[1000][1000]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int visit[1000][1000]{};
	queue<pair<ii, int> > Q;
	cin >> M >> N;
	int mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				Q.push({ {i,j},0 });
				visit[i][j]++;
			}
		}
	}
	
	while (!Q.empty()) {
		ii now = Q.front().first;
		int day = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = now.first + dir[i][0];
			int y = now.second + dir[i][1];
			if (x >= 0 && x < N && y >= 0 && y < M && !visit[x][y] && map[x][y] == 0) {
				Q.push({ {x,y},day + 1 });
				map[x][y] = 1;
				visit[x][y]++;
				mx = max(mx, day + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << mx;

}