#include <iostream>
using namespace std;

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
			//cout << "Push {" << x / 9 << ',' << x % 9 << "} : " << i << '\n';
			if (solve(x + 1))	return true;
			map[x / 9][x % 9] = 0;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
	solve(0);
	cout << '\n';
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)	cout << map[i][j] << ' ';
		cout << '\n';
	}
}