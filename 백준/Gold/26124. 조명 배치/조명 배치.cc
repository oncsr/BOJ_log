#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ii = pair<pair<int, int>, int>;

vector<ii> wait;
int H, W, visit[1000][1000]{}, map[1000][1000]{};
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int vc = 0;
bool cmp(ii a, ii b) {
	if (a.second == b.second) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first.first < b.first.first;
	}
	return a.second > b.second;
}

int bfs(int x, int y, int mx) {
	visit[x][y]++;
	vc++;
	if (mx > 0) {
		queue<ii> Q;
		Q.push({ {x,y},mx });
		while (!Q.empty()) {
			int xx = Q.front().first.first;
			int yy = Q.front().first.second;
			int t = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int xxx = xx + dir[i][0];
				int yyy = yy + dir[i][1];
				if (xxx >= 0 && xxx < H && yyy >= 0 && yyy < W && !visit[xxx][yyy] && map[xxx][yyy] != -1) {
					if (map[xxx][yyy] == t - 1 && t > 1) {
						visit[xxx][yyy]++;
						vc++;
						Q.push({ {xxx,yyy},t - 1 });
					}
					if (map[xxx][yyy] > t + 1)	return -1;
					else if (map[xxx][yyy] < t - 1)	return -1;
				}
			}
		}
		return 1;
	}
	return 0;
}

int main() {
	cin >> H >> W;
	for(int i=0;i<H;i++)
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			wait.push_back({ {i,j},map[i][j] });
		}
	sort(wait.begin(), wait.end(), cmp);
	int cnt = 0;
	for (ii now : wait) {
		int x = now.first.first;
		int y = now.first.second;
		int t = now.second;
		if (!visit[x][y]) {
			int temp = bfs(x, y, t);
			if (temp == -1) {
				cnt = -1;
				break;
			}
			cnt += temp;
		}
	}
	cout << cnt;
}