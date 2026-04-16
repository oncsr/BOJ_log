#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	char arr[1001][1001]{};
	pair<int, int> Apos, Bpos;
	int A = 0, B = 0;
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'A')	Apos = { i,j }, A = i + j;
		if (arr[i][j] == 'B')	Bpos = { i,j }, B = i + j;
	}

	if ((A & 1) != (B & 1))	return cout << -1, 0;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<tuple<int, int, int>> Q;
	Q.emplace(Apos.first, Apos.second, 0);
	int prev = 0;
	int vis[1001][1001]{};
	while (!Q.empty()) {
		auto [x, y, t] = Q.front();
		Q.pop();
		if (prev != t) {
			if (Bpos.first == 1) {
				if (Bpos.second == M)	Bpos.first++;
				else	Bpos.second++;
			}
			else if (Bpos.first == N) {
				if (Bpos.second == 1)	Bpos.first--;
				else	Bpos.second--;
			}
			else {
				if (Bpos.second == 1)	Bpos.first--;
				else	Bpos.first++;
			}
			prev = t;
		}

		if (make_pair(x, y) == Bpos)	return cout << t, 0;

		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 1 || xx > N || yy < 1 || yy > M || vis[xx][yy] || arr[xx][yy] == 'G')	continue;
			vis[xx][yy]++;
			Q.emplace(xx, yy, t + 1);
		}
	}
	cout << -1;

}