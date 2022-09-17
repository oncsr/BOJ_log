#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	int n, m;
	cin >> n >> m;
	string a[51];
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int visit[51][51] = { 0 };
			if (!visit[i][j] && a[i][j] == 'L') {
				queue<pair<pair<int, int>, int> > Q;
				Q.push({ { i,j }, 0 });
				visit[i][j]++;
				int time = 0;
				while (!Q.empty()) {
					int x = Q.front().first.first;
					int y = Q.front().first.second;
					time = Q.front().second;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int xx = x + dir[k][0];
						int yy = y + dir[k][1];
						if(xx < n && xx >= 0 && yy < m && yy >= 0)
							if (!visit[xx][yy] && a[xx][yy] == 'L') {
								Q.push({ { xx,yy }, time + 1 });
								visit[xx][yy]++;
							}
					}
				}
				mx = max(mx, time);
			}
		}
	cout << mx << '\n';
}