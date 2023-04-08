#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[2047][11]{};
	for (int i = 0; i < 2047; i++)
		for (int j = 0; j < 11; j++)
			cin >> arr[i][j];
	for (int j = 0; j < 11; j++) {
		int a = arr[0][j], b = -1000001;
		int cnta = 1, cntb = 0;
		for (int i = 1; i < 2047; i++) {
			if (arr[i][j] != a) {
				if (cntb == 0)	b = arr[i][j];
				cntb++;
			}
			else	cnta++;
		}
		if (cnta == 1023)	cout << a << ' ';
		else	cout << b << ' ';
	}
}