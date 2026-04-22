#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

/*
 < 2022.03.13 >
 [my rating]
 > G2
 [used algorithm]
 > dp, bfs
 [point]
 bfs를 돌며 방문하지 않은 지점은 최단거리, 가짓수 갱신해주고
 이미 방문했던 지점은 최단거리가 동일한 지 검사 후 동일하면 가짓수 더해주고
 
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int r, c;
	cin >> r >> c;
	pl d[401][401]{};	// { 최단거리, 가짓수 }
	d[1][1] = { 0,1 };
	int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
	int visit[401][401]{};
	queue<pair<ii, ll> > Q;	// { 좌표, 거리 }
	Q.push({ {1,1},0 });
	while (!Q.empty()) {
		ii now = Q.front().first;
		ll dis = Q.front().second;
		Q.pop();
		for (int i = 0; i < 8; i++) {
			int x = now.first + dir[i][0];
			int y = now.second + dir[i][1];
			if (x >= 1 && x <= r && y >= 1 && y <= c) {
				if (d[x][y].first == 0) {
					d[x][y].first = d[now.first][now.second].first + 1;
					d[x][y].second = d[now.first][now.second].second;
				}
				else {
					if (d[x][y].first == d[now.first][now.second].first + 1) {
						d[x][y].second += d[now.first][now.second].second;
						d[x][y].second %= 1000000009;
					}
				}
				if (!visit[x][y]) {
					visit[x][y]++;
					Q.push({ {x,y},dis + 1 });
				}
			}
		}
	}
	if (d[r][c].first == 0) {
		if (r == 1 && c == 1)	cout << "0 1";
		else	cout << "None";
	}
	else {
		cout << d[r][c].first << ' ' << d[r][c].second;
	}
}