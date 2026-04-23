#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N, P, Q, s = 1;
	cin >> M >> N >> P >> Q;
	while (M > 0) {
		int map1[20][20]{}, map2[20][20]{};
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> map1[i][j];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < Q; j++)
				cin >> map2[i][j];
		cout << "Case #" << s++ << ":\n";
		if (N == P) {
			for (int i = 0; i < M; i++) {
				cout << "| ";
				for (int j = 0; j < Q; j++) {
					int ss = 0;
					for (int k = 0; k < N; k++)
						ss += map1[i][k] * map2[k][j];
					cout << ss << ' ';
				}
				cout << "|\n";
			}
		}
		else	cout << "undefined\n";
		cin >> M >> N >> P >> Q;
	}
}