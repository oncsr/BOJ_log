#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[100][100]{}, vis[10001]{};
	ii pos[10001]{};
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			pos[arr[i][j]] = { i,j };
		}
	
	int ans = 0;
	for (int i = 1; i <= N * M; i++) {
		if (vis[i])	continue;
		vis[i]++;
		queue<ii> Q;
		int visit[100][100]{};
		ii st = pos[i];
		visit[st.first][st.second]++;
		Q.push(st);
		int cnt = 0;
		while (!Q.empty()) {
			ii now = Q.front();
			int num = arr[now.first][now.second];
			Q.pop();
			cnt++;
			for (int k = 0; k < 4; k++) {
				int x = now.first + dir[k][0];
				int y = now.second + dir[k][1];
				if (x >= 0 && x < N && y >= 0 && y < M) {
					if (!visit[x][y] && arr[x][y] > num) {
						visit[x][y]++;
						Q.push({ x,y });
						vis[arr[x][y]]++;
					}
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}