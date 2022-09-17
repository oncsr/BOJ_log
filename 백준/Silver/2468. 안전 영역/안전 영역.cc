#include <iostream>
#include <queue>
using namespace std;

int N;
int graph[101][101];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int bfs(int h) {
	int visit[101][101] = { 0 };
	queue<pair<int, int> > Q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] > h && !visit[i][j]) {
				Q.push({ i,j });
				visit[i][j]++;
				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int xx = x + dir[k][0];
						int yy = y + dir[k][1];
						if (!visit[xx][yy] && graph[xx][yy] > h) {
							Q.push({ xx,yy });
							visit[xx][yy]++;
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int maxh = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			graph[i][j] = a;
			maxh = max(a, maxh);
		}

	int mx = 0;
	for (int i = 0; i <= maxh; i++)
		mx = max(mx, bfs(i));
	cout << mx << '\n';
}