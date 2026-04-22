#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	char arr[2000][2000]{};
	int dir[7][2] = { {1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
	cin >> n;
	ii st;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'F')	st = { i,j };
		}

	int visit[2000][2000]{};
	visit[st.first][st.second]++;
	queue<ii> Q;
	Q.push(st);
	int cnt = 0;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 7; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n && !visit[xx][yy] && arr[xx][yy] != '#') {
				visit[xx][yy]++;
				cnt++;
				Q.push({ xx,yy });
			}
		}
	}
	cout << cnt;
}