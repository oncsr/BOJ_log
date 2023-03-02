#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<pair<int, int>, char>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	char map[1000][1000]{};
	int map2[1000][1000]{};
	int visit[1000][1000]{};
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int dir2[4][2] = { {1,1},{1,-1},{-1,-1},{-1,1} };
	cin >> N;
	visit[0][0]++, visit[N - 1][N - 1]++;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j])	continue;
			queue<ii> Q;
			int s = 0;
			Q.push({ i,j });
			visit[i][j]++;
			char c = map[i][j];
			queue<ii> Q2;
			Q2.push({ i,j });
			while (!Q.empty()) {
				ii now = Q.front();
				Q.pop();
				s++;
				for (int k = 0; k < 4; k++) {
					int x = now.first + dir[k][0];
					int y = now.second + dir[k][1];
					if (x >= 0 && x < N && y >= 0 && y < N && map[x][y] == c && !visit[x][y]) {
						Q.push({ x,y });
						Q2.push({ x,y });
						visit[x][y]++;
					}
				}
			}
			while (!Q2.empty()) {
				ii now = Q2.front();
				Q2.pop();
				map2[now.first][now.second] = s;
			}
		}
	}

	int ans = 1000001;
	priority_queue<iii, vector<iii>, greater<> > PQ;
	PQ.push({ {0,1000001 }, ' ' });	//	down = 1000001
	vector<int> dist(1000003, -1);
	dist[1000001] = 0;
	while (!PQ.empty()) {
		int distance = PQ.top().first.first;
		int node = PQ.top().first.second;
		char chk = PQ.top().second;
		PQ.pop();
		if (distance > dist[node])	continue;
		if (node == 1000001) {
			for (int i = 0; i < N - 1; i++) {
				int x = N - 1, y = i;
				int next = x * N + y;
				int cost = map2[x][y];
				char next_c = map[x][y];
				if (chk == map[x][y])	cost = 0;
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
		}
		else {
			int x = node / N;
			int y = node - (x * N);
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
				int next = xx * N + yy;
				int cost = map2[xx][yy];
				char next_c = map[xx][yy];
				if (chk == map[xx][yy])	cost = 0;
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dir2[i][0];
				int yy = y + dir2[i][1];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
				int next = xx * N + yy;
				int cost = map2[xx][yy];
				char next_c = map[xx][yy];
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		if (dist[i] == -1)	continue;
		ans = min(ans, dist[i]);
	}
	for (int i = 1; i < N - 1; i++) {
		int num = i * N + N - 1;
		if (dist[num] == -1)	continue;
		ans = min(ans, dist[num]);
	}

	dist = vector<int>(1000003, -1);
	dist[1000001] = 0;
	PQ.push({ {0,1000001},' ' });

	while (!PQ.empty()) {
		int distance = PQ.top().first.first;
		int node = PQ.top().first.second;
		char chk = PQ.top().second;
		PQ.pop();
		if (distance > dist[node])	continue;
		if (node == 1000001) {
			for (int i = 1; i < N; i++) {
				int x = i, y = 0;
				int next = x * N + y;
				int cost = map2[x][y];
				char next_c = map[x][y];
				if (chk == map[x][y])	cost = 0;
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
		}
		else {
			int x = node / N;
			int y = node - (x * N);
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
				int next = xx * N + yy;
				int cost = map2[xx][yy];
				char next_c = map[xx][yy];
				if (chk == map[xx][yy])	cost = 0;
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dir2[i][0];
				int yy = y + dir2[i][1];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
				int next = xx * N + yy;
				int cost = map2[xx][yy];
				char next_c = map[xx][yy];
				if (dist[next] == -1 || dist[next] > dist[node] + cost) {
					dist[next] = dist[node] + cost;
					PQ.push({ {dist[next], next}, next_c });
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		if (dist[i] == -1)	continue;
		ans = min(ans, dist[i]);
	}
	for (int i = 1; i < N - 1; i++) {
		int num = i * N + N - 1;
		if (dist[num] == -1)	continue;
		ans = min(ans, dist[num]);
	}

	cout << ans;
}