#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string map[1000]{};
	int visit[1000][1000]{};
	for (int i = 0; i < n; i++)	cin >> map[i];
	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				if (j > 0) {
					if (map[i][j] == map[i][j - 1]) {
						check = false;
						break;
					}
				}
				if (i > 0) {
					if (map[i][j] == map[i - 1][j]) {
						check = false;
						break;
					}
				}
				visit[i][j]++;
				char ch = map[i][j];
				int y_lim = m;
				bool safe = false;
				for (int x = i; x < n; x++) {
					for (int y = j; y < y_lim; y++) {
						if (x == i) {
							if (map[x][y] == ch) {
								if (x > 0) {
									if (map[x][y] == map[x - 1][y]) {
										check = false;
										break;
									}
								}
							}
							else {
								y_lim = y;
								break;
							}
						}
						else {
							if (map[x][y] == ch) {
								if (y > 0 && y == j) {
									if (map[x][y] == map[x][y - 1]) {
										check = false;
										break;
									}
								}
							}
							else {
								if (y == j) {
									safe = true;
									break;
								}
								check = false;
								break;
							}
						}
						visit[x][y]++;
					}
					if (safe)	break;
					if (!check)	break;
				}
			}
			if (!check)	break;
		}
		if (!check)	break;
	}
	if (check)	cout << "dd";
	else	cout << "BaboBabo";
}