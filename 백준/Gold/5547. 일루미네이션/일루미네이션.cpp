#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int W, H, V[102][102]{};
	cin >> W >> H;
	int dx[6] = { 1,0,-1,-1,0,1 };
	int dy[6] = { -1,-1,-1,0,1,0 };
	int dx2[6] = { 1,0,-1,-1,0,1 };
	int dy2[6] = { 0,-1,0,1,1,1 };

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> V[i][j];
		}
	}
	queue<pair<int, int>> temp;
	int vis[102][102]{};
	for (int i = 0; i <= H + 1; i++) {
		temp.emplace(i, 0), temp.emplace(i, W + 1);
		vis[i][0]++, vis[i][W + 1]++;
	}
	for (int i = 0; i <= W + 1; i++) {
		temp.emplace(0, i), temp.emplace(H + 1, i);
		vis[0][i]++, vis[H + 1][i]++;
	}
	while (!temp.empty()) {
		auto [x, y] = temp.front();
		temp.pop();
		V[x][y] = 2;
		for (int i = 0; i < 6; i++) {
			int xx, yy;
			if (x & 1)	xx = x + dx2[i], yy = y + dy2[i];
			else	xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx <= H+1 && yy >= 0 && yy <= W+1 && V[xx][yy] == 0 && !vis[xx][yy]) {
				vis[xx][yy]++;
				temp.emplace(xx, yy);
			}
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (V[i][j] == 0 || !vis[i][j])	V[i][j] = 1;
		}
	}
	int check[102][102][6]{}, ans = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (V[i][j] != 1)	continue;
			int cnt = 0;
			for (int k = 0; k < 6; k++) {
				if (check[i][j][k]) { cnt--; continue; }
				cnt++;
				check[i][j][k] = 1;
				if (i & 1) {
					switch (k) {
					case 0:
						check[i][j - 1][3] = 1;
						break;
					case 1:
						check[i - 1][j][4] = 1;
						break;
					case 2:
						check[i - 1][j + 1][5] = 1;
						break;
					case 3:
						check[i][j + 1][0] = 1;
						break;
					case 4:
						check[i + 1][j + 1][1] = 1;
						break;
					case 5:
						check[i + 1][j][2] = 1;
						break;
					}
				}
				else {
					switch (k) {
					case 0:
						check[i][j - 1][3] = 1;
						break;
					case 1:
						check[i - 1][j - 1][4] = 1;
						break;
					case 2:
						check[i - 1][j][5] = 1;
						break;
					case 3:
						check[i][j + 1][0] = 1;
						break;
					case 4:
						check[i + 1][j][1] = 1;
						break;
					case 5:
						check[i + 1][j - 1][2] = 1;
						break;
					}
				}
			}
			ans += cnt;
		}
	}
	cout << ans;

}