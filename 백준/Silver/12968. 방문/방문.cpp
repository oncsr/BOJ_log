#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	if ((r & 1) && (c & 1)) {
		cout << 0;
		return 0;
	}
	cout << 1;
}