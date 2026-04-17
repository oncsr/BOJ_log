#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int ans[1001][1001]{};

	if (!(N & 1)) {
		for (int i = 2; i <= N; i += 2) {
			for (int j = 2; j <= M; j++)	ans[i][j] = 1;
		}
		for (int i = 1; i < N; i += 2)	ans[i][2] = 1;
	}
	else if (!(M & 1)) {
		for (int j = 2; j <= M; j += 2) {
			for (int i = 2; i <= N; i++)	ans[i][j] = 1;
		}
		for (int j = 1; j < M; j += 2)	ans[2][j] = 1;
	}
	else {
		if (N < M) {
			for (int i = 2; i <= N; i += 2) {
				for (int j = 1; j <= M; j++)	ans[i][j] = 1;
			}
			for (int i = 3; i < N; i += 2)	ans[i][1] = 1;
		}
		else {
			for (int j = 2; j <= M; j += 2) {
				for (int i = 1; i <= N; i++)	ans[i][j] = 1;
			}
			for (int j = 3; j < M; j += 2)	ans[1][j] = 1;
		}
	}

	cout << "YES\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)	cout << ans[i][j];
		cout << '\n';
	}

}