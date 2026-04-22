#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int map[2001][2001]{};
int mn = 4000001;
int N, M;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

void dijk(int start) {
	priority_queue<ii, vector<ii>, greater<> > Q;
	vector<int> dk(N * M + 3, -1);
	dk[start] = 0;
	Q.push({ 0,start });
	while (!Q.empty()) {
		int dist = Q.top().first;
		int now = Q.top().second;
		Q.pop();
		if (dist > dk[now])	continue;
		int x, y, next, cost;
		if (now > N * M) {
			for (int i = 2; i <= N; i++) {
				x = i, y = 1;
				cost = map[x][y];
				next = (x - 1) * M + y;
				if (dk[next] == -1 || dk[next] > dk[now] + cost) {
					dk[next] = dk[now] + cost;
					Q.push({ dk[next], next });
				}
			}
			for (int i = 2; i < M; i++) {
				x = N, y = i;
				cost = map[x][y];
				next = (x - 1) * M + y;
				if (dk[next] == -1 || dk[next] > dk[now] + cost) {
					dk[next] = dk[now] + cost;
					Q.push({ dk[next], next });
				}
			}
			continue;
		}
		x = (now - 1) / M + 1, y = now - (x - 1) * M;
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if ((xx == 1 && yy == 1) || (xx == N && yy == M))	continue;
			if (xx >= 1 && xx <= N && yy >= 1 && yy <= M) {
				cost = map[xx][yy];
				next = (xx - 1) * M + yy;
				if (dk[next] == -1 || dk[next] > dk[now] + cost) {
					dk[next] = dk[now] + cost;
					Q.push({ dk[next], next });
				}
			}
		}
	}
	for (int i = 2; i <= M; i++) {
		if (dk[i] == -1)	continue;
		mn = min(mn, dk[i]);
	}
	for (int i = 1; i < N; i++) {
		if (dk[i * M] == -1)	continue;
		mn = min(mn, dk[i * M]);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			map[i][j] ^= 1;
		}

	dijk(N * M + 1);
	cout << mn;
}