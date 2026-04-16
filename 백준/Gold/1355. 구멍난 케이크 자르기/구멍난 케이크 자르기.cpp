#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int C, H, P, Q;
	cin >> C >> H;
	vector<int> garo = { 0,2 * C }, sero = { 0,2 * C };
	cin >> P;
	for (int i = 0; i < P; i++) {
		int a;
		cin >> a;
		garo.push_back(a + C);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;
		sero.push_back(a + C);
	}
	sort(garo.begin(), garo.end());
	sort(sero.begin(), sero.end());

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int vis[201][201]{}, ans = 0, g = 0, s = 0;
	for (int i = 1; i <= 2 * C; i++) {
		if (garo[g + 1] < i)	g++;
		s = 0;
		for (int j = 1; j <= 2 * C; j++) {
			if (sero[s + 1] < j)	s++;
			if (vis[i][j] || ((C - H < j && j <= C + H) && (C - H < i && i <= C + H)))	continue;
			queue<pair<int, int>> Q;
			Q.emplace(i, j);
			vis[i][j]++;
			ans++;
			while (!Q.empty()) {
				auto [x, y] = Q.front();
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k], yy = y + dy[k];
					if (vis[xx][yy] || ((C - H < yy && yy <= C + H) && (C - H < xx && xx <= C + H)))	continue;
					if (garo[g] < xx && xx <= garo[g + 1] && sero[s] < yy && yy <= sero[s + 1]) {
						Q.emplace(xx, yy);
						vis[xx][yy]++;
					}
				}
			}
		}
	}
	cout << ans;

}