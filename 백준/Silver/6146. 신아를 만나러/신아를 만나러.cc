#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
#define x first
#define y second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[1001][1001]{}, X, Y, N;
	cin >> X >> Y >> N;
	X += 500, Y += 500;
	for (; N--;) {
		int a, b;
		cin >> a >> b;
		map[a + 500][b + 500] = 1;
	}
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int visit[1001][1001]{};
	visit[500][500]++;
	queue<pair<ii, int> > Q;
	Q.push({ {500,500},0 });
	while (!Q.empty()) {
		ii now = Q.front().x;
		int dist = Q.front().y;
		Q.pop();
		if (now.x == X && now.y == Y) {
			cout << dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if (xx >= 0 && xx <= 1000 && yy >= 0 && yy <= 1000 && !visit[xx][yy] && !map[xx][yy]) {
				visit[xx][yy]++;
				Q.push({ {xx,yy},dist + 1 });
			}
		}
	}
}