#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int R, C;
char arr[100][100]{};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// from : 0 = left -> right, 1 = right -> left
void swing(int height, int from) {
	int y = (from ? C - 1 : 0);
	int d = (from ? -1 : 1);

	for (; y >= 0 && y < C; y += d) {
		if (arr[height][y] == '.')	continue;
		break;
	}
	if (y < 0 || y >= C)	return;

	arr[height][y] = '.';

	int num = 1;
	int vis[100][100]{};
	char new_map[100][100]{};

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (vis[i][j] || arr[i][j] == '.')	continue;
			queue<ii> Q;
			Q.push({ i,j });
			vis[i][j] = num;
			vector<ii> L;
			while (!Q.empty()) {
				ii now = Q.front();
				L.push_back(Q.front());
				Q.pop();
				for (int d = 0; d < 4; d++) {
					int x = now.first + dx[d];
					int yy = now.second + dy[d];
					if (x >= 0 && x < R && yy >= 0 && yy < C && !vis[x][yy] && arr[x][yy] == 'x') {
						Q.push({ x,yy });
						vis[x][yy] = num;
					}
				}
			}
			int gap = R;
			for (auto e : L) {
				bool find = 0;
				int x = e.first, yy = e.second;
				if (x == R - 1) { gap = 0; break; }
				for (int k = 1; k + x < R; k++) {
					if (arr[x + k][yy] == 'x') {
						if (vis[x + k][yy] == num)	continue;
						find = 1;
						gap = min(gap, k - 1);
					}
				}
				if (!find)	gap = min(gap, R - x - 1);
			}
			
			for (auto e : L) {
				int x = e.first, yy = e.second;
				new_map[x + gap][yy] = 'x';
			}
			num++;

		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (new_map[i][j] == 'x')	arr[i][j] = 'x';
			else	arr[i][j] = '.';
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		swing(R - a, i & 1);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)	cout << arr[i][j];
		cout << '\n';
	}

}