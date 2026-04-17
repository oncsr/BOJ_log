#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

pair<int, char> arr[101][101]{};
int N, M, R;
vector<tuple<int, int, int>> ATT;
vector<ii> DEF;
int score = 0;

// 도미노 쓰러뜨리기 함수
void down(char dir, int x, int y, int k) {
	if (dir == 'E') {
		for (int j = y + 1; j <= M && j <= y + k; j++) {
			if (arr[x][j].second == 'S') {
				score++;
				arr[x][j].second = 'F';
				down(dir, x, j, arr[x][j].first - 1);
			}
		}
	}
	else if (dir == 'W') {
		for (int j = y - 1; j >= 1 && j >= y - k; j--) {
			if (arr[x][j].second == 'S') {
				score++;
				arr[x][j].second = 'F';
				down(dir, x, j, arr[x][j].first - 1);
			}
		}
	}
	else if (dir == 'S') {
		for (int i = x + 1; i <= N && i <= x + k; i++) {
			if (arr[i][y].second == 'S') {
				score++;
				arr[i][y].second = 'F';
				down(dir, i, y, arr[i][y].first - 1);
			}
		}
	}
	else {
		for (int i = x - 1; i >= 1 && i >= x - k; i--) {
			if (arr[i][y].second == 'S') {
				score++;
				arr[i][y].second = 'F';
				down(dir, i, y, arr[i][y].first - 1);
			}
		}
	}
}

void solve() {
	// 반복문으로 R개의 라운드 수행
	for (int i = 0; i < R; i++) {
		// 공격수 턴
		auto [x, y, z] = ATT[i];
		if (arr[x][y].second == 'S') {
			score++;
			arr[x][y].second = 'F';
			down(z, x, y, arr[x][y].first - 1);
		}

		// 수비수 턴
		auto [p, q] = DEF[i];
		arr[p][q].second = 'S';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a;
			cin >> a;
			arr[i][j] = { a,'S' };
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
			cout << arr[i][j].second << ' ';
		}
		cout << '\n';
	}

}