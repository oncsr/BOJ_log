#include <bits/stdc++.h>
using namespace std;

int ans[3073][6147]{};

void recur(int n, int x, int y) {
	if (n == 3) {
		ans[x][y + 2] = ans[x + 1][y + 1] = ans[x + 1][y + 3] = 1;
		for (int i = y; i < y + 5; i++)	ans[x + 2][i] = 1;
		return;
	}
	int g = n / 2;
	recur(g, x, y + g);
	recur(g, x + g, y);
	recur(g, x + g, y + 2 * g);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	recur(n, 1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++)	cout << (ans[i][j] ? '*' : ' ');
		cout << '\n';
	}
	
}