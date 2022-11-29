#include<iostream>
#include<queue>
using namespace std;
struct dot {
	int x, y;
	dot operator+(dot a) { return { x + a.x,y + a.y }; }
};
dot dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<vector<int> > vis(8);
int map[8][8]{}, n, m, k = 0, a, base = 0, add = 0, use = 0, mx = 0;
bool isin(dot v) {
	return v.x >= 0 && v.x < n&& v.y >= 0 && v.y < m;
}
void bfs(queue<dot> v) {
	add = 0;
	vector<vector<int> > visit = vis;
	while (!v.empty()) {
		dot s = v.front();
		v.pop();
		for (int i = 0; i < 4; i++) {
			dot g = s + dir[i];
			if (isin(g) && !visit[g.x][g.y] && map[g.x][g.y] == 0) {
				visit[g.x][g.y]++;
				v.push(g);
				add++;
			}
		}
	}
	mx = max(mx, use - 3 - add);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	queue<dot> v;
	for (cin >> n >> m; k < n; k++)
		for (int j = 0; j < m; j++) {
			cin >> a;
			map[k][j] = a;
			if (a < 2) {
				vis[k].push_back(0);
				use += a == 1;
			}
			else {
				vis[k].push_back(1);
				v.push({ k,j });
				vis[k][j]++;
				base++;
			}
		}
	use = n * m - use - base;
	for (int a = 0; a < n * m; a++) {
		int i1 = a / m, j1 = a % m;
		if (map[i1][j1])	continue;
		map[i1][j1] = 1;
		for (int b = a + 1; b < n * m; b++) {
			int i2 = b / m, j2 = b % m;
			if (map[i2][j2])	continue;
			map[i2][j2] = 1;
			for (int c = b + 1; c < n * m; c++) {
				int i3 = c / m, j3 = c % m;
				if (map[i3][j3])	continue;
				map[i3][j3] = 1;
				bfs(v);
				map[i3][j3] = 0;
			}
			map[i2][j2] = 0;
		}
		map[i1][j1] = 0;
	}
	cout << mx;
}