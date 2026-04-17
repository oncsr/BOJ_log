#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	
	int K, N1, M1, N2, M2, A, B, R1, C1, R2, C2;
	cin >> K >> N1 >> M1 >> N2 >> M2 >> A >> B >> R1 >> C1 >> R2 >> C2;
	// blackhole info : { x, y, dim }
	auto next_bh = [&](int x, int y, int dim) -> pair<int, int> {
		int n = dim ? N2 : N1, m = dim ? M2 : M1;
		if (x & 1) {
			if (y == 0)	x = (x + 1) % n;
			else	y--;
		}
		else {
			if (y == m - 1)	x++;
			else	y++;
		}
		return { x,y };
	};

	queue<tuple<int, int, int, int>> BH;
	int vis[200][200][2]{}, bh[200][200][2]{};
	int gate[200][200][2]{};
	for (int i = 0; i < 200; i++)	for (int j = 0; j < 200; j++)	bh[i][j][0] = bh[i][j][1] = 10000000;
	for (int i = 0; i < K; i++) {
		int d, dr, dc;
		cin >> d >> dr >> dc;
		d--;
		BH.emplace(d, dr, dc, 1);
		bh[dr][dc][d] = 1;
	}
	while (!BH.empty()) {
		auto [d, x, y, t] = BH.front();
		BH.pop();
		auto [xx, yy] = next_bh(x, y, d);
		if (bh[xx][yy][d] == 10000000) {
			bh[xx][yy][d] = t + 1;
			BH.emplace(d, xx, yy, t + 1);
		}
	}

	queue<tuple<int, int, int, int, int>> Q;
	Q.emplace(0, 0, 0, 0, 0);

	while (!Q.empty()) {
		auto [t, x, y, d, p] = Q.front();
		Q.pop();
		//cout << "[pos = " << x << "," << y << "] [dim = " << d << "] [time = " << t << "] [p = " << p << "]\n";
		if (p) {
			if (p == 1) {
				if (!vis[x][y][d]) {
					Q.emplace(t + 1, x, y, d, p - 1);
				}
			}
			else	Q.emplace(t + 1, x, y, d, p - 1);
			continue;
		}
		if (x == N2 - 1 && y == M2 - 1 && d == 1) {
			cout << t;
			return 0;
		}
		int n = d ? N2 : N1, m = d ? M2 : M1;
		int r = d ? R2 : R1, c = d ? C2 : C1;
		// dim shift
		// can use gate
		if (r <= x && x < r + A && c <= y && y < c + B) {
			// destination visit check
			int diffx = x - r, diffy = y - c;
			int rr = d ? R1 : R2, cc = d ? C1 : C2;
			if (!gate[x][y][d] && bh[rr + diffx][cc + diffy][d ^ 1] > t + 4) {
				gate[x][y][d]++;
				gate[rr + diffx][cc + diffy][d ^ 1];
				Q.emplace(t + 1, rr + diffx, cc + diffy, d ^ 1, 2);
			}
		}

		// JM moving
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy][d] && bh[xx][yy][d] > t + 2) {
				Q.emplace(t + 1, xx, yy, d, 0);
				vis[xx][yy][d]++;
			}

		}
	}
	cout << "hing...";

}