#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
string arr[26];
bool visit[26][26] = { false };
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int bfs(int n, int m)
{
	int house = 1;
	queue<pair<int, int> > Q;
	Q.push({ n,m });
	visit[n][m] = true;
	while (!Q.empty()) {
		int xx = Q.front().first;
		int yy = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = xx + dir[i][0];
			int y = yy + dir[i][1];
	
			if (x < N && y < N && x >= 0 && y >= 0)
			{
				if (arr[x][y] == '1' && !visit[x][y])
				{
					Q.push({ x,y });
					visit[x][y] = true;
					house++;
				}
			}
		}
	}
	return house;
}



int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int cnt = 0;
	vector<int> s;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == '1' && !visit[i][j])
			{
				s.push_back(bfs(i, j));
				cnt++;
			}
		}
	cout << cnt << '\n';
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << '\n';
}