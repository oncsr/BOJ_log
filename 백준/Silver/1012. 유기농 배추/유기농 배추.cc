#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int main() {
	int t;	cin >> t;
	while (t--) {
		bool ground[51][51] = { false };
		bool visit[51][51] = { false };
		int m, n, k;
		cin >> m >> n >> k;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			ground[b][a] = true;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && ground[i][j]) {
					queue<pair<int, int> > Q;
					visit[i][j] = true;
					Q.push({ i, j });
					while (!Q.empty()) {
						int x = Q.front().first;
						int y = Q.front().second;
						Q.pop();
						for (int p = 0; p < 4; p++) {
							int xx = x + dir[p][0];
							int yy = y + dir[p][1];
							if (xx < n && yy < m && xx >= 0 && yy >= 0)
								if (!visit[xx][yy] && ground[xx][yy]) {
									Q.push({ xx,yy });
									visit[xx][yy] = true;
								}
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}