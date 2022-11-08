#include <iostream>
using namespace std;

int main() {
	int N, M, d[1001][1001]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> d[i][j];
			d[i][j] += max(d[i - 1][j - 1], max(d[i][j - 1], d[i - 1][j]));
		}
	}
	cout << d[N][M];
}