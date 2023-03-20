#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

struct dot {
	int xx, yy, zz;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int M, N, H, map[100][100][100]{};
	int dir[6][3] = { {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };
	int visit[100][100][100]{};
	queue<pair<dot, int> > Q;
	cin >> M >> N >> H;
	int mx = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					Q.push({ {i,j,k},0 });
					visit[i][j][k]++;
				}
			}
		}
	}
	
	while (!Q.empty()) {
		dot now = Q.front().first;
		int day = Q.front().second;
		Q.pop();
		for (int i = 0; i < 6; i++) {
			int x = now.xx + dir[i][0];
			int y = now.yy + dir[i][1];
			int z = now.zz + dir[i][2];
			if (x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H&& !visit[x][y][z] && map[x][y][z] == 0) {
				Q.push({ {x,y,z},day + 1 });
				map[x][y][z] = 1;
				visit[x][y][z]++;
				mx = max(mx, day + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << mx;

}