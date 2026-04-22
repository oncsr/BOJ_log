#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int, int>;
using node = pair<ii, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int H, W;
	cin >> H >> W;
	char map[500][500]{};
	ii st, ed;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'K')	st = { i,j };
			if (map[i][j] == '*')	ed = { i,j };
		}
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
	int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
	vector<int> temp(500, -1);
	vector<vector<int> > vis(500, temp);
	queue<node> Q;
	vis[st.first][st.second] = 0;
	Q.push({ st,0 });
	int mn = -1;
	while (!Q.empty()) {
		ii now = Q.front().first;
		int dist = Q.front().second;
		Q.pop();
		if (dist > vis[now.first][now.second])	continue;
		if (now == ed) {
			if (mn == -1)	mn = dist;
			else	mn = min(mn, dist);
			continue;
		}
		for (int i = 0; i < 8; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];
			if (x >= 0 && x < H && y >= 0 && y < W && map[x][y] != '#') {
				if (vis[x][y] == -1) {
					if (dy[i] == 1)	vis[x][y] = dist, Q.push({ {x,y},dist });
					else	vis[x][y] = dist + 1, Q.push({ {x,y},dist + 1 });
				}
				else {
					if (dy[i] == 1 && vis[x][y] > dist)
						vis[x][y] = dist, Q.push({ {x,y},dist });
					else if (dy[i] != 1 && vis[x][y] > dist + 1)
						vis[x][y] = dist + 1, Q.push({ {x,y},dist + 1 });
				}
			}
		}
	}
	cout << mn;
	
}