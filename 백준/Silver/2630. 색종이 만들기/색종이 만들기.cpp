#include <bits/stdc++.h>
using namespace std;

int N, white = 0, blue = 0;
int arr[129][129]{};

void Cut(int x, int y, int len) {
	int temp_white = 0, temp_blue = 0;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == 0)	temp_white++;
			else	temp_blue++;
		}
	}
	// 탈출 조건
	if (temp_white == len * len) {
		white++;
		return;
	}
	if (temp_blue == len * len) {
		blue++;
		return;
	}

	Cut(x, y, len / 2);
	Cut(x, y + len / 2, len / 2);
	Cut(x + len / 2, y, len / 2);
	Cut(x + len / 2, y + len / 2, len / 2);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	Cut(0, 0, N);

	cout << white << '\n' << blue;

}