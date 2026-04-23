#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[301][301]{};
	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			map[i][j] = map[i - 1][j] + map[i][j - 1] + a - map[i - 1][j - 1];
		}
	}
	int s = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int x = i; x <= n; x++) {
				if (map[x][j] - map[x][j - 1] - map[i - 1][j] + map[i - 1][j - 1] > 10)	break;
				for (int y = j; y <= m; y++) {
					s = map[x][y] - map[x][j - 1] - map[i - 1][y] + map[i - 1][j - 1];
					if (s == 10)
						cnt++;
				}
			}
		}
	}
	cout << cnt;
}
