#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[5][5]{}, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c[5]{};
		for (int j = 0; j < 5; j++)	cin >> c[j];
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (c[j] && c[k])	arr[j][k]++;
			}
		}
	}
	int mx = 0, x, y;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i][j] > mx)	mx = arr[i][j], x = i, y = j;
		}
	}
	cout << mx << '\n';
	if (mx == 0) {
		cout << "1 1 0 0 0";
	}
	else {
		for (int i = 0; i < 5; i++) {
			if (i == x || i == y)	cout << "1 ";
			else	cout << "0 ";
		}
	}
}