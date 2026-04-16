#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N;
char arr[50][50]{};
int dx[6] = { -1,-1,0,0,1,1 };
int dy[6] = { 0,1,-1,1,-1,0 };

bool chk(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	int X = 0;
	int Y = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		char a;
		cin >> a;
		arr[i][j] = a;
		if (a == '-') continue;
		X++;
		int c = 0;
		for (int k = 0; k < 3; k++) {
			int x = i + dx[k], y = j + dy[k];
			if (!chk(x, y) || arr[x][y] == '-') continue;
			c |= (1 << k);
		}
		Y += c > 0;
	}
	if (!X) return cout << 0, 0;
	if (!Y) return cout << 1, 0;
	int col[50][50]{};
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (arr[i][j] == '-') continue;
		if (col[i][j]) continue;
		queue<tuple<int, int, int>> Q;
		Q.emplace(i, j, 1);
		col[i][j] = 1;
		while (!Q.empty()) {
			auto[x, y, v] = Q.front();
			Q.pop();
			for (int k = 0; k < 6; k++) {
				int xx = x + dx[k], yy = y + dy[k];
				if (!chk(xx, yy) || arr[xx][yy] == '-') continue;
				if (!col[xx][yy]) {
					Q.emplace(xx, yy, v == 1 ? 2 : 1);
					col[xx][yy] = v == 1 ? 2 : 1;
				}
				else if (col[xx][yy] == v) return cout << 3, 0;
			}
		}
	}
	cout << 2;

}