#include <iostream>
using namespace std;

/*
* 2022.12.08
* [used algorithm]
* => dp
* [point]
* => 맞왜틀
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, map[1001][1001], a, b, c, d, D[1001][1001]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	cin >> a >> b >> c >> d;
	if (!(a == c && b == d)) { // 벽이 있는 경우

		if (a == c) {	// 벽이 가로
			if (b > d)	swap(b, d);
			// 가지 못하는 칸에 대한 전처리
			if (b == 0) {
				if (a)
					for (int i = a + 1; i <= N; i++)
						for (int j = 1; j <= d; j++)
							D[i][j] = -2000000001;
			}
			else if (d == M) {
				for (int i = 1; i <= a; i++)
					for (int j = b + 1; j <= M; j++)
						D[i][j] = -2000000001;
			}
			//

			for (int i = 1; i <= N; i++) {
				if (i == a + 1) {
					for (int j = b + 1; j <= d; j++)	D[i - 1][j] = -2000000001;
				}
				for (int j = 1; j <= M; j++) {
					if (D[i][j] == -2000000001)	continue;
					if (i == 1 && j == 1)	D[i][j] = map[i][j];
					else if (i == 1) {
						if (D[i][j - 1] == -2000000001)	D[i][j] = -2000000001;
						else	D[i][j] = map[i][j] + D[i][j - 1];
					}
					else if (j == 1) {
						if (D[i - 1][j] == -2000000001)	D[i][j] = -2000000001;
						else	D[i][j] = map[i][j] + D[i - 1][j];
					}
					else {
						if (D[i - 1][j] == -2000000001 && D[i][j - 1] == -2000000001)	D[i][j] = -2000000001;
						else if (D[i - 1][j] == -2000000001)	D[i][j] = map[i][j] + D[i][j - 1];
						else if (D[i][j - 1] == -2000000001)	D[i][j] = map[i][j] + D[i - 1][j];
						else	D[i][j] = map[i][j] + max(D[i - 1][j], D[i][j - 1]);
					}
				}
			}

		}
		else {	// 벽이 세로
			if (a > c)	swap(a, c);
			// 가지 못하는 칸에 대한 전처리
			if (a == 0) {
				if (b)
					for (int i = 1; i <= c; i++)
						for (int j = b + 1; j <= M; j++)
							D[i][j] = -2000000001;
			}
			else if (c == N) {
				for (int i = a + 1; i <= N; i++)
					for (int j = 1; j <= b; j++)
						D[i][j] = -2000000001;
			}
			//

			for (int j = 1; j <= M; j++) {
				if (j == b + 1) {
					for (int i = a + 1; i <= c; i++)	D[i][j - 1] = -2000000001;
				}
				for (int i = 1; i <= N; i++) {
					if (D[i][j] == -2000000001)	continue;
					if (i == 1 && j == 1)	D[i][j] = map[i][j];
					else if (i == 1) {
						if (D[i][j - 1] == -2000000001)	D[i][j] = -2000000001;
						else	D[i][j] = map[i][j] + D[i][j - 1];
					}
					else if (j == 1) {
						if (D[i - 1][j] == -2000000001)	D[i][j] = -2000000001;
						else	D[i][j] = map[i][j] + D[i - 1][j];
					}
					else {
						if (D[i - 1][j] == -2000000001 && D[i][j - 1] == -2000000001)	D[i][j] = -2000000001;
						else if (D[i - 1][j] == -2000000001)	D[i][j] = map[i][j] + D[i][j - 1];
						else if (D[i][j - 1] == -2000000001)	D[i][j] = map[i][j] + D[i - 1][j];
						else	D[i][j] = map[i][j] + max(D[i - 1][j], D[i][j - 1]);
					}
				}
			}

		}
	}
	else {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				if (i == 1 && j == 1)	D[i][j] = map[i][j];
				else if (i == 1)	D[i][j] = map[i][j] + D[i][j - 1];
				else if (j == 1)	D[i][j] = map[i][j] + D[i - 1][j];
				else	D[i][j] = map[i][j] + max(D[i - 1][j], D[i][j - 1]);
			}
	}
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)	cout << D[i][j] << ' ';
		cout << '\n';
	}
	*/
	if (D[N][M] == -2000000001)	cout << "Entity";
	else	cout << D[N][M];
}