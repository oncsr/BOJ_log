#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int graph[10][10]{}, R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			cin >> a;
			if (a == 'X')	graph[i][j] = 1;
			else	graph[i][j] = 0;
		}
	}
	bool res = false;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 1)	continue;
			int wall = 0, way = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < R && y >= 0 && y < C) {
					if (graph[x][y] == 1)	wall++;
					way++;
				}
			}
			if (way - wall < 2)	res = true;
		}
	}
	cout << (int)res;
}