#include <iostream>
using namespace std;

/*
* 2022.11.26
* [used algorithm]
* =>
* [point]
* =>
*/

int main() {
	int N, M, a, map[1000][1000]{};
	int zero = 0, one = 0, other = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			map[i][j] ? one++ : zero++;
			if (!i && !j)	continue;
			if (!j) {
				if (map[i][j] == map[i - 1][j])	other = 0;
			}
			else {
				if (map[i][j] == map[i][j - 1])	other = 0;
			}
		}
	}
	if (other)	cout << -1;
	else {
		if (zero % 2 || one % 2)	cout << -1;
		else	cout << 1;
	}
}