#include <bits/stdc++.h>
using namespace std;

char arr[65][65]{};
string ans = "";

void divide(int x, int y, int len) {
	if (len == 1) {
		ans += arr[x][y];
		return;
	}

	int zero = 0, one = 0;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == '0')	zero++;
			else	one++;
		}
	}

	if (zero == len * len) {
		ans += '0';
		return;
	}
	if (one == len * len) {
		ans += '1';
		return;
	}

	ans += '(';
	divide(x, y, len / 2);
	divide(x, y + len / 2, len / 2);
	divide(x + len / 2, y, len / 2);
	divide(x + len / 2, y + len / 2, len / 2);
	ans += ')';
}

int main() {
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	divide(1, 1, N);
	cout << ans;
}