#include <iostream>
#include <algorithm>
using namespace std;

int paper[501][501];
bool visited[501][501] = { false };
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int n, m;

int dfs(int a, int b)
{
	int w = 1;
	visited[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		int x = a + dir[i][0];
		int y = b + dir[i][1];
		if (x < n && y < m && x >= 0 && y >= 00)
			if (paper[x][y] == 1 && !visited[x][y])
				w += dfs(x, y);
	}
	return w;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	
	int cnt = 0;
	int ans = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && paper[i][j] == 1)
			{
				ans = max(ans, dfs(i, j));
				cnt++;
			}
		}
	cout << cnt << '\n' << ans << '\n';
}