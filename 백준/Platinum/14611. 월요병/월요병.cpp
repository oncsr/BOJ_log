#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using li = pair<ll, int>;
#define x first
#define y second


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[300][300]{}, n, m;
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	int visit1[300][300]{};
	visit1[0][0]++;
	queue<ii> Q1;
	Q1.push({ 0,0 });
	bool possible = true;
	while (!Q1.empty()) {
		ii now = Q1.front();
		Q1.pop();
		if (now.x == n - 1 && now.y == m - 1) {
			possible = false;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && map[xx][yy] == -1 && !visit1[xx][yy]) {
				Q1.push({ xx,yy });
				visit1[xx][yy]++;
			}
		}
	}
	// 막을 수 있는 경우
	if (possible) {
		
		int dir[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
		vector<vector<int> > V(90002);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == -1)	continue;
				for (int k = 0; k < 8; k++) {
					int xx = i + dir[k][0];
					int yy = j + dir[k][1];
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && map[xx][yy] != -1) {
						int start = i * m + j;
						int end = xx * m + yy;
						V[start].push_back(end);
					}
				}
			}
		}
		// 왼쪽 벽은 N*M번, 아래쪽 벽은 N*M+1번 정점으로 하자
		for (int i = 0; i < n; i++) {
			if (map[i][0] == -1)	continue;
			int num = i * m;
			V[n * m].push_back(num);
		}
		for (int i = 0; i < m; i++) {
			if (map[n - 1][i] == -1)	continue;
			int num = (n - 1) * m + i;
			V[n * m + 1].push_back(num);
		}
		ll ans = 1000000000000000000;
		priority_queue<li, vector<li>, greater<> > PQ;
		vector<ll> dist(90002, -1);
		dist[n * m] = 0;
		PQ.push({ 0, n * m });
		while (!PQ.empty()) {
			ll distance = PQ.top().x;
			int node = PQ.top().second;
			PQ.pop();
			if (distance > dist[node])	continue;
			for (int next : V[node]) {
				int xx = next / m;
				int yy = next - (xx * m);
				if (dist[next] == -1 || dist[next] > max(0, map[xx][yy]) + dist[node]) {
					dist[next] = max(0, map[xx][yy]) + dist[node];
					PQ.push({ dist[next], next });
				}
			}
		}
		for (int i = 1; i < m; i++) {
			if (dist[i] == -1)	continue;
			ans = min(ans, dist[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			int num = i * m + m - 1;
			if (dist[num] == -1)	continue;
			ans = min(ans, dist[num]);
		}

		dist = vector<ll>(90002, -1);
		dist[n * m + 1] = 0;
		PQ.push({ 0, n * m + 1 });
		while (!PQ.empty()) {
			ll distance = PQ.top().x;
			int node = PQ.top().second;
			PQ.pop();
			if (distance > dist[node])	continue;
			for (int next : V[node]) {
				int xx = next / m;
				int yy = next - (xx * m);
				if (dist[next] == -1 || dist[next] > max(0, map[xx][yy]) + dist[node]) {
					dist[next] = max(0, map[xx][yy]) + dist[node];
					PQ.push({ dist[next], next });
				}
			}
		}
		for (int i = 1; i < m; i++) {
			if (dist[i] == -1)	continue;
			ans = min(ans, dist[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			int num = i * m + m - 1;
			if (dist[num] == -1)	continue;
			ans = min(ans, dist[num]);
		}
		cout << ans;
	}
	else	cout << -1;
}