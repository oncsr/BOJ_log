#include <iostream>
using namespace std;

int main() {
	pair<int, int> argue[9]{};
	int b;
	for (int i = 0; i < 9; i++) {
		cin >> b >> argue[i].second;
		argue[i].first = b ? 1 : -1;
	}
	int find = 0, ans = -1;
	for (int i = 0; i < 9; i++) {
		int a[10]{};
		a[argue[i].second] = argue[i].first == 1 ? -1 : 1;
		bool cont = false;
		for (int j = 0; j < 9; j++) {
			if (j == i)	continue;
			if (a[argue[j].second] == 0) {
				a[argue[j].second] = argue[j].first;
			}
			else {
				if (a[argue[j].second] != argue[j].first) {
					cont = true;
					break;
				}
			}
		}
		if (!cont) {
			int one = 0, temp = 0, zero = 0, minus = 0;
			for (int j = 1; j <= 9; j++) {
				if (a[j] == 1) {
					one++;
					temp = j;
				}
				else if (a[j] < 0)	minus++;
				else zero = j;

			}
			if (one > 1)	cont = true;
			else if (one != 1) {
				if (minus == 8)	temp = zero;
				else {
					find = 0;
					ans = -1;
					break;
				}
			}
			if (!cont) {
				find++;
				ans = temp;
			}

		}
	}
	cout << (find == 1 ? ans : -1);
}