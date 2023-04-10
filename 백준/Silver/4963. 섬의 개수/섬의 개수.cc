#include <iostream>
#include <queue>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	int dir[8][2] = { {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
	while (w != 0 || h != 0) {
		int arr[51][51];
		int visit[51][51] = { 0 };
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && arr[i][j]) {
					queue<pair<int, int> > Q;
					Q.push({ i,j });
					visit[i][j]++;
					while (!Q.empty()) {
						int x = Q.front().first;
						int y = Q.front().second;
						Q.pop();
						for (int k = 0; k < 8; k++) {
							int xx = x + dir[k][0];
							int yy = y + dir[k][1];
							if(xx < h && xx >= 0 && yy < w && yy >= 0)
								if (!visit[xx][yy] && arr[xx][yy]) {
									Q.push({ xx,yy });
									visit[xx][yy]++;
								}
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		cin >> w >> h;
	}
}