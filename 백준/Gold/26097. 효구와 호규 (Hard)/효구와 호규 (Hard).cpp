#include <iostream>
#include <queue>
using namespace std;
#define print cout<<x+1<<' '<<y+1<<' '<<x2+1<<' '<<y2+1<<'\n'
using ii = pair<int, int>;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, map[1000][1000]{}, visit[1000][1000]{};
	int zero = 0, one = 0, other = 1, x, y, x2, y2;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			map[i][j] ? one++ : zero++;
			if (!i && !j)	continue;
			if (!j) {
				if (map[i][j] == map[i - 1][j]) {
					other = 0;
					x = i, y = j;
					x2 = i - 1, y2 = j;
				}
			}
			else {
				if (map[i][j] == map[i][j - 1]) {
					other = 0;
					x = i, y = j;
					x2 = i, y2 = j - 1;
				}
			}
		}
	}
	if (other)	cout << -1;
	else {
		if (zero % 2 || one % 2)	cout << -1;
		else {
			cout << "1\n";
			queue<ii> One;
			queue<ii> Zero;
			int temp = map[x][y];
			visit[x][y]++;
			visit[x2][y2]++;
			print;
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];
				if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visit[xx][yy]) {
					visit[xx][yy]++;
					if (!map[xx][yy])	Zero.push({xx,yy});
					else	One.push({ xx,yy });
				}
			}
			for (int i = 0; i < 4; i++) {
				int xx = x2 + dir[i][0];
				int yy = y2 + dir[i][1];
				if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visit[xx][yy]) {
					visit[xx][yy]++;
					if (!map[xx][yy])	Zero.push({xx,yy});
					else	One.push({ xx,yy });
				}
			}
			while (!Zero.empty() || !One.empty()) {
				if (Zero.size() > 1) {
					x = Zero.front().first;
					y = Zero.front().second;
					Zero.pop();
					x2 = Zero.front().first;
					y2 = Zero.front().second;
					Zero.pop();
				}
				else {
					x = One.front().first;
					y = One.front().second;
					One.pop();
					x2 = One.front().first;
					y2 = One.front().second;
					One.pop();
				}
				print;
				for (int i = 0; i < 4; i++) {
					int xx = x + dir[i][0];
					int yy = y + dir[i][1];
					if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visit[xx][yy]) {
						visit[xx][yy]++;
						if (!map[xx][yy])	Zero.push({xx,yy});
						else	One.push({ xx,yy });
					}
				}
				for (int i = 0; i < 4; i++) {
					int xx = x2 + dir[i][0];
					int yy = y2 + dir[i][1];
					if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visit[xx][yy]) {
						visit[xx][yy]++;
						if (!map[xx][yy])	Zero.push({ xx,yy });
						else	One.push({ xx,yy });
					}
				}
			}
		}
	}
}