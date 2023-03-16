#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N, M, T;
	char map[50][50]{};
	char map2[50][50]{};
	
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j], map2[i][j] = map[i][j];

	ll les = min(N, M);
	ll red = 0, green = 0, blue = 0;
	int re = 0;

	if (N == 1) {
		for (int j = 0; j < M; j++) {
			if (map[0][j] == 'R')	red++;
			if (map[0][j] == 'G')	green++;
			if (map[0][j] == 'B')	blue++;
		}
		cout << red * T << '\n' << green * T << '\n' << blue * T;
		return 0;
	}
	if (M == 1) {
		for (int i = 0; i < N; i++) {
			if (map[i][0] == 'R')	red++;
			if (map[i][0] == 'G')	green++;
			if (map[i][0] == 'B')	blue++;
		}
		cout << red * T << '\n' << green * T << '\n' << blue * T;
		return 0;
	}

	while (T > 1 && re < les - 1) {
		
		for (int i = 0; i < N; i++) {
			if (map2[i][0] == 'R')	red++;
			if (map2[i][0] == 'G')	green++;
			if (map2[i][0] == 'B')	blue++;
		}
		for (int i = 1; i < M; i++) {
			if (map2[0][i] == 'R')	red++;
			if (map2[0][i] == 'G')	green++;
			if (map2[0][i] == 'B')	blue++;
		}
		
		char temp[50][50]{};

		for (int i = 1; i < N; i++)
			for (int j = 1; j < M; j++)
				temp[i - 1][j - 1] = map2[i][j];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.') {
					if (temp[i][j] == 0)	temp[i][j] = '.';
				}
				else {
					temp[i][j] = map[i][j];
				}
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map2[i][j] = temp[i][j];
		

		T--, re++;
	}

	
	if (!T) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map2[i][j] == 'R')	red++;
				if (map2[i][j] == 'G')	green++;
				if (map2[i][j] == 'B')	blue++;
			}
		}
		cout << red << '\n' << green << '\n' << blue;
		return 0;
	}

	ll corn_red = 0, corn_green = 0, corn_blue = 0;
	for (int i = 0; i < N; i++) {
		if (map2[i][0] == 'R')	corn_red++;
		if (map2[i][0] == 'G')	corn_green++;
		if (map2[i][0] == 'B')	corn_blue++;
	}
	for (int i = 1; i < M; i++) {
		if (map2[0][i] == 'R')	corn_red++;
		if (map2[0][i] == 'G')	corn_green++;
		if (map2[0][i] == 'B')	corn_blue++;
	}

	red += corn_red * (T - 1);
	green += corn_green * (T - 1);
	blue += corn_blue * (T - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 'R')	red++;
			if (map2[i][j] == 'G')	green++;
			if (map2[i][j] == 'B')	blue++;
		}
	}
	cout << red << '\n' << green << '\n' << blue;

	

}