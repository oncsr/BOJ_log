#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

ii arr[101][101]{};
int N, M, R;
vector<tuple<int, int, int>> ATT;
vector<ii> DEF;
int score = 0;

void down(char dir, int x, int y, int k) {
	if (dir == 'E') {
		for (int j = y + 1; j <= M && j <= y + k; j++) {
			if (arr[x][j].second == 1) {
				score++;
				arr[x][j].second = 0;
				down(dir, x, j, arr[x][j].first - 1);
			}
		}
	}
	else if (dir == 'W') {
		for (int j = y - 1; j >= 1 && j >= y - k; j--) {
			if (arr[x][j].second == 1) {
				score++;
				arr[x][j].second = 0;
				down(dir, x, j, arr[x][j].first - 1);
			}
		}
	}
	else if (dir == 'S') {
		for (int i = x + 1; i <= N && i <= x + k; i++) {
			if (arr[i][y].second == 1) {
				score++;
				arr[i][y].second = 0;
				down(dir, i, y, arr[i][y].first - 1);
			}
		}
	}
	else {
		for (int i = x - 1; i >= 1 && i >= x - k; i--) {
			if (arr[i][y].second == 1) {
				score++;
				arr[i][y].second = 0;
				down(dir, i, y, arr[i][y].first - 1);
			}
		}
	}
}

void solve() {
	for (int i = 0; i < R; i++) {
		auto [x, y, z] = ATT[i];
		if (arr[x][y].second == 1) {
			score++;
			arr[x][y].second = 0;
			down(z, x, y, arr[x][y].first - 1);
		}
		auto [p, q] = DEF[i];
		arr[p][q].second = 1;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a;
			cin >> a;
			arr[i][j] = { a,1 };
		}
	}

	for (int i = 0; i < R; i++) {
		int x, y;
		char a;
		cin >> x >> y >> a;
		ATT.push_back({ x,y,a });
		cin >> x >> y;
		DEF.push_back({ x,y });
	}

	solve();

	cout << score << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << (arr[i][j].second ? 'S' : 'F') << ' ';
		}
		cout << '\n';
	}

}