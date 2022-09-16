#include <iostream>
#include <queue>
using namespace std;
int N, M;
string arr[101];
int visit[101][101] = { 0 };
int sum1 = 0, sum2 = 0;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void bfs(int i, int j) {
	queue<pair<int, int> > Q;
	int cnt = 0;
	char ch = arr[i][j];
	if (!visit[i][j]) {
		Q.push({ i,j });
		visit[i][j]++;
		cnt++;
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int k = 0; k < 4; k++) {
				int xx = x + dir[k][0];
				int yy = y + dir[k][1];
				if (xx < N && xx >= 0 && yy < M && yy >= 0) {
					if (!visit[xx][yy] && arr[xx][yy] == ch) {
						Q.push({ xx,yy });
						visit[xx][yy]++;
						cnt++;
					}
				}
			}
		}
	}
	if (ch == 'W')
		sum1 += (cnt * cnt);
	else
		sum2 += (cnt * cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			bfs(i, j);
	cout << sum1 << ' ' << sum2 << '\n';
}