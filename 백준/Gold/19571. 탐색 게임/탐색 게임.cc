#include <iostream>
using namespace std;


int main() {
	int map[100][100]{};
	int id = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = i + 1; j <= 99 - i; j++)	map[i][j] = ++id;
		for (int ii = 98 - i; ii > i; ii--)	map[ii][99 - i] = ++id;
	}
	map[99][50] = ++id;
	for (int i = 0; i < 100; i++) {
		if (i == 50)	continue;
		map[99][i] = ++id;
	}
	for (int i = 98, k = 1; i >= 0; i--, k++) {
		for (int j = 0; j < 100 - k; j++)	map[i][j] = ++id;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}