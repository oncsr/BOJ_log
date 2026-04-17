#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
	int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

	int T;
	for (cin >> T; T--;) {

		int L;
		cin >> L;
		pair<int, int> start, end;

		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		int visit[300][300]{};

		visit[start.first][start.second]++;
		queue<tuple<int, int, int>> Q;
		Q.push({ start.first, start.second, 0 });

		while (!Q.empty()) {
			auto [x, y, time] = Q.front();
			Q.pop();

			if (make_pair(x, y) == end) {
				cout << time << '\n';
				break;
			}

			for (int i = 0; i < 8; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x >= 0 && next_x < L && next_y >= 0 && next_y < L) {
					if (visit[next_x][next_y] != 0)	continue;
					//
					Q.push({ next_x, next_y, time + 1 });
					visit[next_x][next_y]++;
				}
			}

		}

		

	}

}