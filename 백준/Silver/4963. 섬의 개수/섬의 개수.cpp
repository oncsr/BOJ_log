#include <iostream>
#include <queue>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	while (w != 0 && h != 0) {
		int arr[51][51]{};
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];
		int cnt = 0;
		int visit[51][51]{};
		int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
		int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
		queue<pair<int, int> > Q;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && visit[i][j] == 0) {
					visit[i][j]++;
					Q.push({ i,j });
					while (!Q.empty()) {
						int now_x = Q.front().first;
						int now_y = Q.front().second;
						Q.pop();
						for (int k = 0; k < 8; k++) {
							int next_x = now_x + dx[k];
							int next_y = now_y + dy[k];
							if (next_x >= 0 && next_x < h && next_y >= 0 && next_y < w) {
								if (visit[next_x][next_y] == 0 && arr[next_x][next_y]) {
									Q.push({ next_x,next_y });
									visit[next_x][next_y]++;
								}
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