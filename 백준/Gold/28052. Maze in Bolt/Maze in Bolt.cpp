#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int R, C;
int map[1000][100]{};
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

// visit[i][j] : 오른쪽으로 j번 돌린 너트가 i번 행에 존재할 수 있는가?

bool bfs(vector<int> origin) {
	vector<vector<int> > block(R, vector<int>(C, 0));
	vector<vector<int> > visit(R, vector<int>(C, 0));
	for (int k = 0; k < C; k++)
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				block[i][k] |= (origin[j] & map[i][(j + k) % C]);

	for (int i = 0; i < C; i++) {
		if (block[0][i] || visit[0][i])	continue;
		queue<pair<int, int> > Q;
		visit[0][i]++;
		Q.push({ 0,i });
		while (!Q.empty()) {
			int row = Q.front().first;
			int rotate = Q.front().second;
			Q.pop();
			if (row == R - 1)	return true;
			for (int k = 0; k < 4; k++) {
				int next_row = row + dir[k][0];
				int next_rotate = (rotate + dir[k][1] + C) % C;
				if (next_row >= 0 && next_row < R) {
					if (block[next_row][next_rotate])	continue;
					if (visit[next_row][next_rotate])	continue;
					Q.push({ next_row,next_rotate });
					visit[next_row][next_rotate]++;
				}
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C;
	vector<int> origin(C);
	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		origin[i] = a - '0';
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			cin >> a;
			map[i][j] = a - '0';
		}
	}
	if (bfs(origin)) {
		cout << 'Y';
		return 0;
	}
	reverse(origin.begin(), origin.end());
	if (bfs(origin)) {
		cout << 'Y';
		return 0;
	}
	cout << 'N';
}