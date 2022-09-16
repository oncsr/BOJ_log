#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int visit[101][101] = { 0 };

int main() {
	int arr[101][101] = { 0 };
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		arr[x - 1][y - 1]++;
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || !arr[i][j])
				visit[i][j]++;
			else {
				visit[i][j]++;
				queue<pair<int, int> > Q;
				Q.push({ i,j });
				int cnt = 1;
				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int xx = x + dir[k][0];
						int yy = y + dir[k][1];
						if (xx < N && xx >= 0 && yy < M && yy >= 0)
							if (!visit[xx][yy] && arr[xx][yy]) {
								Q.push({ xx,yy });
								cnt++;
								visit[xx][yy]++;
							}
					}
				}
				total = max(cnt, total);
			}
		}
	}
	cout << total << '\n';
}