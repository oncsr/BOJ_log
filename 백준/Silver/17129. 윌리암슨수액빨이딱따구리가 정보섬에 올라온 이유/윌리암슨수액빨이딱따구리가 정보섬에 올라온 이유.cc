#include <iostream>
#include <queue>
using namespace std;

struct node { int x, y, t; };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, vis[3000][3000]{}, map[3000][3000]{}, x, y;
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	cin >> n >> m;
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
			if (map[i][j] == 2)	x = i, y = j;
		}
	}
	queue<node> Q;
	Q.push({ x,y,0 });
	vis[x][y]++;
	bool yes = false;
	while (!Q.empty()) {
		node now = Q.front();
		Q.pop();
		if (map[now.x][now.y] > 2) {
			yes = true;
			cout << "TAK\n" << now.t;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && map[xx][yy] != 1) {
				vis[xx][yy]++;
				Q.push({ xx,yy,now.t + 1 });
			}
		}
	}
	if (!yes)	cout << "NIE";
}