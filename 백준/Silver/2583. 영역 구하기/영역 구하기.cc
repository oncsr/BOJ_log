#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	int S[101][101] = { 0 };
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++) {
			for (int k = a; k < c; k++)
				S[j][k]++;
		}
	}
	int visit[101][101] = { 0 };
	queue<pair<int, int> > Q;
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int cnt = 0;
	int sum = 0;
	vector<int> V;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && S[i][j] == 0) {
				Q.push({ i,j });
				visit[i][j]++;
				sum = 0;
				while (!Q.empty()) {
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					sum++;
					for (int k = 0; k < 4; k++) {
						int xx = x + dir[k][0];
						int yy = y + dir[k][1];
						if (xx < N && xx >= 0 && yy < M && yy >= 0) {
							if (!visit[xx][yy] && S[xx][yy] == 0) {
								Q.push({ xx,yy });
								visit[xx][yy]++;
							}
						}
					}
				}
				V.push_back(sum);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
}