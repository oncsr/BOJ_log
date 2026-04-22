#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N, M;
		cin >> N >> M;
		int arr[101]{};
		int map[100][100]{};
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == -1)	continue;
				if (j + 1 < M) {
					if (map[i][j] == map[i][j + 1])	arr[map[i][j]]++;
					if (i + 1 < N) {
						if (map[i][j] == map[i + 1][j + 1])	arr[map[i][j]]++;
					}
				}
				if (i + 1 < N) {
					if (map[i][j] == map[i + 1][j])	arr[map[i][j]]++;
					if (j - 1 >= 0) {
						if (map[i][j] == map[i + 1][j - 1])	arr[map[i][j]]++;
					}
				}
			}
		}
		int s = 0;
		for (int i = 0; i <= 100; i++) {
			if (!arr[i])	continue;
			s++;
		}
		cout << s << '\n';
	}
}