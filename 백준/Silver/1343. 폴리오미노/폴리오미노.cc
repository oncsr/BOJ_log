#include <iostream>
using namespace std;

int main() {
	string a, b = "";
	cin >> a;
	int x = 0, no = 0;
	for (auto& i : a) {
		if (i == 'X')	x++;
		else {
			if (x % 2) {
				no++;
				break;
			}
			else {
				if (x >= 4) {
					for (int j = 0; j < x / 4; j++)	b += "AAAA";
					x %= 4;
				}
				if (x >= 2) {
					for (int j = 0; j < x / 2; j++)	b += "BB";
					x %= 2;
				}
			}
			b += '.';
		}
	}
	while (x) {
		if (x % 2) {
			no++;
			break;
		}
		else {
			if (x >= 4) {
				for (int j = 0; j < x / 4; j++)	b += "AAAA";
				x %= 4;
			}
			if (x >= 2) {
				for (int j = 0; j < x / 2; j++)	b += "BB";
				x %= 2;
			}
		}
	}
	if (no)	cout << -1;
	else	cout << b;
}