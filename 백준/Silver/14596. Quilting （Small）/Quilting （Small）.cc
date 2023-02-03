#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[101][100]{}, H, W, a, mn = 6502501;
	cin >> H >> W;
	for (int i = 1; i <= H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a;
			map[i][j] = (a - map[i][j]) * (a - map[i][j]);
			int g = map[i - 1][j];
			if (j >= 1)	g = min(map[i - 1][j - 1], g);
			if (j + 1 < W)	g = min(map[i - 1][j + 1], g);
			map[i][j] += g;
			if (i == H)	mn = min(mn, map[i][j]);
		}
	}
	cout << mn;
}