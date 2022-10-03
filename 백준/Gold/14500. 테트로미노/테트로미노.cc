#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[500][500]{};
	int n, m, mx = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 3; j++)
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3]);
	for (int i = 0; i < n - 3; i++)
		for (int j = 0; j < m; j++)
			mx = max(mx, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j]);

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1]);

	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 1; j++) {
			mx = max(mx, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1]);
			mx = max(mx, map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1]);
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j]);
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			
			mx = max(mx, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			mx = max(mx, map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j]);

			mx = max(mx, map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			mx = max(mx, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1]);
		}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 2; j++) {
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j]);
			mx = max(mx, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2]);
			mx = max(mx, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			mx = max(mx, map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);

			mx = max(mx, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			mx = max(mx, map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2]);

			mx = max(mx, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
			mx = max(mx, map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);
		}
	
	cout << mx;
}