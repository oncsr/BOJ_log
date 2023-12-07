#include <bits/stdc++.h>
using namespace std;

/*
* 1. bfs로 각 물 공간에 번호를 부여하자.
* 2. bfs로 빙판을 시간 단위로 녹이며,
* 깨지는 빙판마다 그 사방을 보며 연결할 수 있는 물 공간이 있으면 분리 집합으로 합쳐
* 3. 시간이 달라지면, find로 두 백조의 root가 같아졌는지 확인
*/

vector<int> root;
int R, C, A = -1, B = -1;
char arr[1500][1500]{};
int num[1500][1500]{};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void init_island_number() {
	int cnt = 0;
	int vis[1500][1500]{};
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'X' || vis[i][j])	continue;
			queue<pair<int, int>> Q;
			Q.emplace(i, j);
			vis[i][j]++;
			cnt++;
			while (!Q.empty()) {
				auto [x, y] = Q.front();
				num[x][y] = cnt;
				if (arr[x][y] == 'L') {
					if (A == -1)	A = cnt;
					else	B = cnt;

				}
				Q.pop();
				for (int d = 0; d < 4; d++) {
					int xx = x + dx[d], yy = y + dy[d];
					if (xx >= 0 && xx < R && yy >= 0 && yy < C && !vis[xx][yy] && arr[xx][yy] != 'X') {
						Q.emplace(xx, yy);
						vis[xx][yy]++;
					}
				}
			}
		}
	}
	root.resize(cnt + 1);
	iota(root.begin(), root.end(), 0);
}

void solve() {
	init_island_number();
	queue<tuple<int, int, int>> Q;
	int vis[1500][1500]{};
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'X')	continue;
			Q.emplace(i, j, 0);
			vis[i][j]++;
		}
	}

	int temp_time = 0;
	while (!Q.empty()) {
		auto [x, y, t] = Q.front();
		Q.pop();
		if (t != temp_time) {
			int X = find(A), Y = find(B);
			if (X == Y) {
				cout << t << '\n';
				return;
			}
			temp_time = t;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < R && yy >= 0 && yy < C && !vis[xx][yy]) {
				Q.emplace(xx, yy, t + 1);
				vis[xx][yy]++;
				arr[xx][yy] = '.';
				num[xx][yy] = num[x][y];
				for (int d = 0; d < 4; d++) {
					int xxx = xx + dx[d], yyy = yy + dy[d];
					if (xxx >= 0 && xxx < R && yyy >= 0 && yyy < C && arr[xxx][yyy] != 'X') {
						int X = find(num[xx][yy]), Y = find(num[xxx][yyy]);
						root[X] = Y;
					}
				}
			}
		}
	}

}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)	for (int j = 0; j < C; j++)	cin >> arr[i][j];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int TC;
	TC = 1;
	for (; TC--;) {
		input();
		solve();
	}

}