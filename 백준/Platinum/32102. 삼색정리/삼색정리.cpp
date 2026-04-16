#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, R, G, B;
	cin >> N >> M >> R >> G >> B;

	int mx = max({ R, G, B }), mn = min({ R, G, B });
	if (mx > (N * M + 1) / 2)	return cout << "NO", 0;
	cout << "YES\n";

	int sw = 0;
	if (N == 2)	swap(N, M), sw = 1;

	char a, b, c;
	int x = mx, y = mn, z = N * M - x - y;
	if (mx == R) {
		a = 'R';
		if (mn == G)	b = 'G', c = 'B';
		else	b = 'B', c = 'G';
	}
	else if (mx == G) {
		a = 'G';
		if (mn == R)	b = 'R', c = 'B';
		else	b = 'B', c = 'R';
	}
	else {
		a = 'B';
		if (mn == R)	b = 'R', c = 'G';
		else	b = 'G', c = 'R';
	}

	char ans[2000][2000]{};
	int i = 0, j = 0, round = 0;
	while (x--) {
		ans[i][j] = a;
		j += 2;
		if (j >= M) {
			i++;
			if (i == N)	i = 0, round++;
			j = i & 1 ^ round;
		}
	}
	while (y--) {
		ans[i][j] = b;
		j += 2;
		if (j >= M) {
			i++;
			if (i == N)	i = 0, round++;
			j = i & 1 ^ round;
		}
	}
	while (z--) {
		ans[i][j] = c;
		j += 2;
		if (j >= M) {
			i++;
			if (i == N)	i = 0, round++;
			j = i & 1 ^ round;
		}
	}
	if (sw) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)	cout << ans[j][i];
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)	cout << ans[i][j];
			cout << '\n';
		}
	}

}