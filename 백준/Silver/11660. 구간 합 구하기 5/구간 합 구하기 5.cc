#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[1025][1025]{};
	int n, m, a, x, y, xx, yy;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			map[i][j] = map[i - 1][j] + map[i][j - 1] + a - map[i - 1][j - 1];
		}
	}
	while (m--) {
		cin >> x >> y >> xx >> yy;
		cout << map[xx][yy] - map[xx][y - 1] - map[x - 1][yy] + map[x - 1][y - 1] << '\n';
	}
}
