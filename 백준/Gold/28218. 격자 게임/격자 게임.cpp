#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	char ground[301][301];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
		}
	}

	int dp[301][301];
	dp[N - 1][M - 1] = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (i == N - 1 && j == M - 1)	continue;
			if (ground[i][j] == '.') {
				dp[i][j] = 0;
				if (i + 1 < N) {
					if (ground[i + 1][j] == '.' && dp[i + 1][j] == 0) {
						dp[i][j] = 1;
					}
				}
				if (j + 1 < M) {
					if (ground[i][j + 1] == '.' && dp[i][j + 1] == 0) {
						dp[i][j] = 1;
					}
				}
				for (int s = 1; s <= K; s++) {
					if (i + s < N && j + s < M) {
						if (ground[i + s][j + s] == '.' && dp[i + s][j + s] == 0) {
							dp[i][j] = 1;
						}
					}
				}
			}
		}
	}

	int Q;
	cin >> Q;
	int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (dp[a - 1][b - 1] == 0) cout << "Second" << "\n";
		else cout << "First" << "\n";
	}
}