#include <iostream>
using namespace std;

struct shark {
	int weight, speed, direction;
};

shark map[101][101][102]{};
int ans = 0, R, C, M, r, c, s, d, z, cnt = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r][c][1] = {z,s,d};
	}
	while (++cnt <= C) {
		// 상어 잡기
		int a = 0;
		for (int i = 1; i <= R; i++) {
			if (map[i][cnt][cnt].weight) {
				a = map[i][cnt][cnt].weight;
				map[i][cnt][cnt] = {0,0,0};
				break;
			}
		}
		ans += a;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				// 상어가 있으면
				if (map[i][j][cnt].weight) {
					int w = map[i][j][cnt].weight;
					int sp = map[i][j][cnt].speed;
					int di = map[i][j][cnt].direction;
					// 위, 아래로 움직이는 상어일 경우
					int g;
					if (di == 2) {
						if (i + sp > R) {
							g = (i + sp) % (2 * R - 2);
							if (g == 0) {
								g = 2;
								di = 1;
							}
							else if (g > R) {
								g = 2 * R - g;
								di = 1;
							}
						}
						else	g = i + sp;
						// 그 자리에 상어가 없거나 나보다 작은 애가 있으면
						if (!(map[g][j][cnt + 1].weight && map[g][j][cnt+1].weight > w)) {
							map[g][j][cnt+1] = {w,sp,di};
						}
					}
					else if (di == 1) {
						if (i - sp < 1) {
							g = 1;
							di = 2;

							if (g + sp - i + 1 > R) {
								g = (g + sp - i + 1) % (2 * R - 2);
								if (g == 0) {
									g = 2;
									di = 1;
								}
								else if (g > R) {
									g = 2 * R - g;
									di = 1;
								}
							}
							else	g = g + sp - i + 1;
							// 그 자리에 상어가 없거나 나보다 작은 애가 있으면
							if (!(map[g][j][cnt + 1].weight && map[g][j][cnt + 1].weight > w)) {
								map[g][j][cnt + 1] = { w,sp,di};
							}
						}
						else {
							g = i - sp;
							if (!(map[g][j][cnt + 1].weight && map[g][j][cnt + 1].weight > w)) {
								map[g][j][cnt + 1] = { w,sp,di};
							}
						}
					}
					else if (di == 3) {
						if (j + sp > C) {
							g = (j + sp) % (2 * C - 2);
							if (g == 0) {
								g = 2;
								di = 4;
							}
							else if (g > C) {
								g = 2 * C - g;
								di = 4;
							}
						}
						else	g = j + sp;
						// 그 자리에 상어가 없거나 나보다 작은 애가 있으면
						if (!(map[i][g][cnt + 1].weight && map[i][g][cnt+1].weight > w)) {
							map[i][g][cnt+1] = {w,sp,di};
						}
					}
					else {
						if (j - sp < 1) {
							g = 1;
							di = 3;

							if (g + sp - j + 1 > C) {
								g = (g + sp - j + 1) % (2 * C - 2);
								if (g == 0) {
									g = 2;
									di = 4;
								}
								else if (g > C) {
									g = 2 * C - g;
									di = 4;
								}
							}
							else	g = g + sp - j + 1;
							// 그 자리에 상어가 없거나 나보다 작은 애가 있으면
							if (!(map[i][g][cnt + 1].weight && map[i][g][cnt + 1].weight > w)) {
								map[i][g][cnt + 1] = { w,sp,di};
							}
						}
						else {
							g = j - sp;
							if (!(map[i][g][cnt + 1].weight && map[i][g][cnt + 1].weight > w)) {
								map[i][g][cnt + 1] = { w,sp,di};
							}
						}
					}
				}
			}
		}
		/*
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j][cnt + 1].weight)	cout << "1 ";
				else	cout << "0 ";
			}
			cout << '\n';
		}
		*/
	}
	cout << ans;
}