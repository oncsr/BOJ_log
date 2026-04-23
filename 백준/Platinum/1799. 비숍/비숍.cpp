#include <iostream>
using namespace std;

int N, mx1 = 0, map[10][10]{}, mx = 0;
void D(int s, int p, int c) {
	if (N % 2 == 0 && c > N / 2) {
		c -= N / 2;
		if ((p % N) == 0)	p++;
		else	p--;
	}
	int x = p / N, y = p % N;
	if (p >= N * N - 2) {
		if (!map[x][y])	mx1 = max(mx1, s + 1);
		else	mx1 = max(mx1, s);
		return;
	}
	if (!map[x][y]) {
		for (int i = 0; i < N; i++) {
			if (x + i < N && y - i >= 0) {
				if (!map[x + i][y - i])
					map[x + i][y - i] = p + 3;
			}
			else	break;
		}
		for (int i = 0; i < N; i++) {
			if (x + i < N && y + i < N) {
				if (!map[x + i][y + i])
					map[x + i][y + i] = p + 3;
			}
			else	break;
		}
		D(s + 1, p + 2, c + 1);
		for (int i = 0; i < N; i++) {
			if (x + i < N && y - i >= 0) {
				if (map[x + i][y - i] == p + 3)
					map[x + i][y - i] = 0;
			}
			else	break;
		}
		for (int i = 0; i < N; i++) {
			if (x + i < N && y + i < N) {
				if (map[x + i][y + i] == p + 3)
					map[x + i][y + i] = 0;
			}
			else	break;
		}
	}
	D(s, p + 2, c + 1);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map[i][j] ^= 1;
		}
	D(0, 0, 1);
	mx += mx1;
	mx1 = 0;
	D(0, 1, 1);
	cout << mx + mx1;
}