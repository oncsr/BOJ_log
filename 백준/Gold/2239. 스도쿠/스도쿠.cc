#include <iostream>
using namespace std;

/*
 < 2022.02.23 >
 [subjective rating]
 > G3
 [used algorithm]
 > backtracking
 [point]
 채워지지 않은 칸에 대하여 가능한 모든 숫자를 차례대로 넣어보기
 재귀함수의 return에 대해 명확히 할 것
*/

int map[9][9]{};

bool solve(int x) {
	if (x == 81)	return true;
	if (map[x / 9][x % 9])	return solve(x + 1);
	int arr[10]{};
	for (int i = 0; i < 9; i++) {
		arr[map[x / 9][i]]++;
		arr[map[i][x % 9]]++;
	}
	int xx = x / 27, yy = (x % 9) / 3;
	for (int i = xx * 3; i < xx * 3 + 3; i++)
		for (int j = yy * 3; j < yy * 3 + 3; j++)
			arr[map[i][j]]++;
	bool suc = false;
	for (int i = 1; i <= 9; i++) {
		if (!arr[i]) {
			map[x / 9][x % 9] = i;
			if (solve(x + 1))	return true;
			map[x / 9][x % 9] = 0;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < 9; j++)
			map[i][j] = a[j] - '0';
	}
	solve(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)	cout << map[i][j];
		cout << '\n';
	}
}