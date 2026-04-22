#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[10][10]{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int mn = 3001;
	int flower[10][10]{};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int ax = 1; ax < n - 1; ax++) {
		for (int ay = 1; ay < n - 1; ay++) {
			int s = 0;
			flower[ax][ay]++;
			s += arr[ax][ay];
			for (int k = 0; k < 4; k++) {
				int x = ax + dx[k], y = ay + dy[k];
				flower[x][y]++;
				s += arr[x][y];
			}


			for (int bx = 1; bx < n - 1; bx++) {
				for (int by = 1; by < n - 1; by++) {
					if (flower[bx][by])	continue;
					bool can = 0;
					for (int k = 0; k < 4; k++) {
						int x = bx + dx[k], y = by + dy[k];
						can |= (bool)flower[x][y];
					}
					if (can)	continue;

					flower[bx][by]++;
					s += arr[bx][by];
					for (int k = 0; k < 4; k++) {
						int x = bx + dx[k], y = by + dy[k];
						flower[x][y]++;
						s += arr[x][y];
					}
					

					for (int cx = 1; cx < n - 1; cx++) {
						for (int cy = 1; cy < n - 1; cy++) {
							if (flower[cx][cy])	continue;
							can = 0;
							for (int k = 0; k < 4; k++) {
								int x = cx + dx[k], y = cy + dy[k];
								can |= (bool)flower[x][y];
							}
							if (can)	continue;

							flower[cx][cy]++;
							s += arr[cx][cy];
							for (int k = 0; k < 4; k++) {
								int x = cx + dx[k], y = cy + dy[k];
								flower[x][y]++;
								s += arr[x][y];
							}

							mn = min(mn, s);

							flower[cx][cy]--;
							s -= arr[cx][cy];
							
							for (int k = 0; k < 4; k++) {
								int x = cx + dx[k], y = cy + dy[k];
								flower[x][y]--;
								s -= arr[x][y];
							}
						}
					}


					flower[bx][by]--;
					s -= arr[bx][by];
					for (int k = 0; k < 4; k++) {
						int x = bx + dx[k], y = by + dy[k];
						flower[x][y]--;
						s -= arr[x][y];
					}
				}
			}


			flower[ax][ay]--;
			s -= arr[ax][ay];
			for (int k = 0; k < 4; k++) {
				int x = ax + dx[k], y = ay + dy[k];
				flower[x][y]--;
				s -= arr[x][y];
			}
		}
	}
	cout << mn;
}