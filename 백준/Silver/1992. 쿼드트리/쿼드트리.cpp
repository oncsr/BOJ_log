#include <bits/stdc++.h>
using namespace std;

char arr[64][64]{};

void recursion(int x, int y, int len) {
	int zero = 0, one = 0;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == '0')	zero++;
			else	one++;
		}
	}

	if (zero == len * len) {
		cout << 0;
		return;
	}
	if (one == len * len) {
		cout << 1;
		return;
	}

	cout << '(';
	recursion(x, y, len / 2);
	recursion(x, y + len / 2, len / 2);
	recursion(x + len / 2, y, len / 2);
	recursion(x + len / 2, y + len / 2, len / 2);
	cout << ')';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	cin >> arr[i][j];
	recursion(0, 0, n);

}