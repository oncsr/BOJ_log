#include <iostream>
using namespace std;

int main() {
	int n, m, map[100][100]{}, s = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	s += n * m * 2;
	for (int i = 0; i < n; i++) {
		int g = 0;
		for (int j = 0; j < m; j++) {
			if (map[i][j] > g)	s += map[i][j] - g;
			g = map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int g = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (map[i][j] > g)	s += map[i][j] - g;
			g = map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int g = 0;
		for (int j = 0; j < n; j++) {
			if (map[j][i] > g)	s += map[j][i] - g;
			g = map[j][i];
		}
	}
	for (int i = 0; i < m; i++) {
		int g = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (map[j][i] > g)	s += map[j][i] - g;
			g = map[j][i];
		}
	}
	cout << s;
}